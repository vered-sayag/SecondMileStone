//
// Created by davidregev on 31/12/18.
//

#include "MyTestClientHandler.h"
void server_side::MyTestClientHandler::handleClient(int socket) {
    string problem = "";
    string ans;
    while (true) {
        char buf[1024];
        int numBytesRead = recv(socket, buf, sizeof(buf), 0);

        if (numBytesRead > 0) {
            for (int i = 0; i < numBytesRead; i++) {
                char c = buf[i];
                if (c == '\n') {
                    if (problem.length() > 0) {
                        if (!problem.compare(END_MESSAGE)) {
                            close(socket);
                            return;
                        }
                        if (cacheManager->isExist(problem)) {
                            ans = cacheManager->popSolution(problem);
                        } else {
                            ans = solver->solve(problem);
                            cacheManager->pushSolution(problem, ans);
                        }
                        ans = ans+"\n";
                        ssize_t n;

                        // Send message
                        n = write(socket, ans.c_str(), ans.length());

                        if (n < 0) {
                            close(socket);
                            return;
                        }


                        problem = "";
                    }
                } else problem += c;
            }
        } else {
            if (errno == EWOULDBLOCK) {
                continue;
            }
            close(socket);
            return;
        }
    }
}