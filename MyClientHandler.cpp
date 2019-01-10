//
// Created by vered on 1/10/19.
//

#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <regex>
#include "MyClientHandler.h"
#include "MyTestClientHandler.h"

void server_side::MyClientHandler::handleClient(int socket) {
    string line = "";
    string problem = "";
    string ans;
    vector<vector<int>> Vproblem;
    bool end = false;
    char buf[1024];
    int numBytesRead;
    int i;
    while (!end) {
        numBytesRead = recv(socket, buf, sizeof(buf), 0);
        if (numBytesRead > 0) {
            for (i = 0; i < numBytesRead; i++) {
                char c = buf[i];
                if (c == '\n') {
                    if (line.length() > 0) {
                        if (!line.compare(END_MESSAGE)) {
                            end = true;
                            break;
                        }
                        Vproblem.push_back(splitByComma(line));
                        problem += line + ";";
                        line = "";
                    }
                } else line += c;
            }
        } else {
            if (errno == EWOULDBLOCK) {
                continue;
            }
            close(socket);
            return;
        }
    }

    unsigned long coloms=0;
    unsigned long rows = Vproblem.size();
    for (int j = 0; j < rows; j++) {
        if (j == 0) {
            coloms = Vproblem[j].size();
            continue;
        }
        if (Vproblem[j].size() != Vproblem[j - 1].size()) {
            throw invalid_argument("invalid j matrix");
        }
    }


    i++;
    line = "";
    int counter = 2;
    while (counter > 0) {
        if (numBytesRead > 0) {
            for (; i < numBytesRead; i++) {
                char c = buf[i];
                if (c == '\n') {
                    if (line.length() > 0) {
                        if (counter == 0) {
                            break;
                        }
                        counter--;
                        Vproblem.push_back(splitByComma(line));
                        problem += line + ";";
                        line = "";
                    }
                } else line += c;
            }
        } else {
            if (errno == EWOULDBLOCK) {
                continue;
            }
            close(socket);
            return;
        }
        i = 0;
        numBytesRead = recv(socket, buf, sizeof(buf), 0);
    }
    if (Vproblem[Vproblem.size() - 1][0] < 0 || Vproblem[Vproblem.size() - 1][0] > rows - 1
        || Vproblem[Vproblem.size() - 2][0] < 0 || Vproblem[Vproblem.size() - 2][0] > rows - 1
        || Vproblem[Vproblem.size() - 1][1] < 0 || Vproblem[Vproblem.size() - 1][1] > coloms - 1
        || Vproblem[Vproblem.size() - 2][1] < 0 || Vproblem[Vproblem.size() - 2][1] > coloms - 1
        ||Vproblem[Vproblem.size() - 1][0]<Vproblem[Vproblem.size() - 2][0]
        ||Vproblem[Vproblem.size() - 1][1]<Vproblem[Vproblem.size() - 2][1]) {
        throw invalid_argument("the limits of the matrix not goods");
    }
    if (cacheManager->isExist(problem)) {
        ans = cacheManager->popSolution(problem);
    } else {
        ans = solver->solve(Vproblem);
        cacheManager->pushSolution(problem, ans);
    }
    ans = ans + "\n";
    ssize_t n;

    // Send message
    n = write(socket, ans.c_str(), ans.length());

    close(socket);

}

vector<int> server_side::MyClientHandler::splitByComma(string str) {
    vector<int> output;
    regex r("[^,]+");
    std::smatch m;
    while (regex_search(str, m, r)) {
        string s2 = m[0];
        if (regex_match(s2, regex("^\\d+"))) {
            output.push_back(stoi(s2));
        } else {
            throw invalid_argument("invalid matrix");
        }

        // remove everything until after this match, and search again
        str = m.suffix().str();
    }
    return output;
}