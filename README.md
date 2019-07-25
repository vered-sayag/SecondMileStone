	 ______________											 ___________________     
	|    server    |										|	ClientHandler	|    
	|______________|										|___________________|    
open(int port,ClientHandler*) <>----------------------------|handleClient(int socket)    
	|    stop()    |										|___________________|    
	|______________|												^    
			^														|    
	 _______|_______												|    
	|  MyTCPserver  |												|    
	|_______________|										________|___________     
		    ^                                              |	MyClientHandler	|    
		 ___|_______________________________ 	           |____________________|    					
		|                                   |              | Solver<string,vector<vector<double>>>*    
	____|______________ 			 _______|________      | CacheManager		|<>-|              
	| MyParallelServer |			| MySerialServer |	   |____________________|	|    
	|__________________|			| _______________|								|    
																					|    
																____________________|_____________    
	_________________________								   |								  |    
   |	State<Node>		     |								   |								  |    
   |_________________________|					_______________|__________				 _________|_______     
   |Node state				 |				   | Solver<Solution,Problem> |				|   CacheManager  |    
   |double cost				 |				   |__________________________|				|_________________|    
   |State<Node> *comeFrom	 |				   | Solution solve(Problem)  |				|bool isExist(string)    
   |bool visited			 |				   |__________________________|				|pushSolution(string, string)    
   |bool operator==(State<Node>)							^							|string popSolution(string)    
   |Node getState()	         |								|							|__________________|    
   |double getCost()         |								|									 ^     
   | setCost(double cost)    |								|									 |    
   |setCameFrom(State<T> *s) |								|									 |    
   |State<T>* getCameFrom()  |								|									 |    
   |bool isVisited()         |								|									 |    
   |setVisited(bool t)       |								|									 |    
   |_________________________|								|									 |    
							 _______________________________|_____________________ 				 |    
							|SearchSolver: Solver<string, vector<vector<double>>> |		 ________|_________    
							|_____________________________________________________|     | FileCacheManager |    
						|-<>| Searcher<pair<int,int>, vector<State<pair<int,int>*>>>	|__________________|    
						|	| Searchable<pair<int,int>> *searchable				  |    
						|	|_____________________________________________________|    
						|    
		________________|________________________________________________________________    
	 __|_____________________________________ 					   ______________________|_________    
	|	Searchable<Node>					 |					  |	Searche<Node,Solution>		   |    
	|________________________________________|					  |________________________________|    
	|State<Node>* getInitialState()			 |					  |Solution search(Searchable<Node>*)    
	|State<Node>* getGoalState()			 |					  |getNumOfNodesEvaluated()		   |    
	|vector<State<Node>*> getAllPossibleState(State<Node>*)		  |________________________________|    
	|vector<State<Node>*> getAllPossibleState(State<Node>*,State<Node>*)		   ^    
	|_________________________________________|					   ________________|______________________________    
					  ^											  |TraceBackSearcher: Searche<T,vector<State<T>*>>|    
	 _________________|__________________________				  |_______________________________________________|    
	| MatrixSearchable:Searchable<pair<int,int>> |				  |protected:									  |    
	|____________________________________________|				  |vector<State<T>*> backTrace(State<T>*init, State<T> *goal)    
	| MatrixSearchable(vector<vector<double>>)	 |				  |clearAll(vector<State<T> *> output,DBtoSearcher<T>* DB) <>-|    
	|____________________________________________|				  |_______________________________________________|			  |    
																					^										  |    
																					|					   ___________________|___    
					   _____________________________________________________________|					  | DBtoSearcher <Node>	  |    
		   ___________|__		__________|___		 ___________|___		 _______|_____				  |_______________________|    
		  | BFSSearcher  |	   | BFSSearcher  |		| AStarSearcher |		| DFSSearcher |				  |State<T> *popFromOpen()|    
		  |______________|	   |______________|		|_______________|		|_____________|				  |bool emptyOpen() 	  |    
																										  |State<T> *popFromClosed()    
																										  |bool emptyClosed()	  |    
													|---------------------------------------------------->|pushToOpen(State<T>*)  |    
											________|________		____|____		 ____|____			  |pushToClosed(State<T>*)|    
										   | PriorityQueueDB |	   | QueueDB |		| StackDB |			  |bool 					isInExistVector(State<T>*)    
										   |_________________|	   |_________|		|_________|			  |_______________________|     
