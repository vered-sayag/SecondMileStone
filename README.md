 ______________________________							 ________________________     
|    server    				   |						|	ClientHandler		 |   						|______________________________| 						|________________________|
|open(int port,ClientHandler*) | <>---------------------|handleClient(int socket)|    
|    stop() 				   |						|________________________|    
|______________________________|									^    
			^														|    
	 _______|_______												|    
	|  MyTCPserver	|												|    
	|_______________|										________|_______________________________     
		    ^                                              |	MyClientHandler						|    
		 ___|_______________________________ 	           |________________________________________|    					
		|                                   |              | Solver<string,vector<vector<double>>>* |   
	____|______________ 			 _______|________      | CacheManager							|<>-|              
	| MyParallelServer |			| MySerialServer |	   |________________________________________|	|    
	|__________________|			| _______________|							    ____________________|    
																					|    
																____________________|_____________    
	____________________________							   |								  |    
   |	State<Node>		     	|							   |								  |    
   |____________________________|				_______________|__________				 _________|_____________________     
   |Node state				 	|			   | Solver<Solution,Problem> |				|   CacheManager  				|    
   |double cost				 	|			   |__________________________|				|_______________________________|    
   |State<Node> *comeFrom	 	|			   | Solution solve(Problem)  |				|bool isExist(string)			|    
   |bool visited			 	|			   |__________________________|				|pushSolution(string, string)	|    
   |bool operator==(State<Node>)|							^							|string popSolution(string)		|    
   |Node getState()	         	|							|							|_______________________________|    
   |double getCost()         	|							|									 ^     
   | setCost(double cost)    	|							|									 |    
   |setCameFrom(State<T> *s) 	|							|									 |    
   |State<T>* getCameFrom()  	|							|									 |    
   |bool isVisited()         	|							|									 |    
   |setVisited(bool t)       	|							|									 |    
   |____________________________|							|									 |    
							 _______________________________|_______________________ 			 |    
							|SearchSolver: Solver<string, vector<vector<double>>> 	|	 ________|_________    
							|_____________________________________________________	|   | FileCacheManager |    
						|-<>| Searcher<pair<int,int>, vector<State<pair<int,int>*>>>|	|__________________|    
						|	| Searchable<pair<int,int>> *searchable				  	|    
						|	|_______________________________________________________|    
						|    
	____________________|_______________________________________________________________________    
 __|_____________________________________________________________		  ______________________|_________    
|	Searchable<Node>											 	|	 |	Searche<Node,Solution>			|    
|___________________________________________________________________| 	 |__________________________________|    
|State<Node>* getInitialState()			 							|	 |Solution search(Searchable<Node>*)|    
|State<Node>* getGoalState()			 							|	 |getNumOfNodesEvaluated()			|    
|vector<State<Node>*> getAllPossibleState(State<Node>*)			 	| 	 |__________________________________|    
|vector<State<Node>*> getAllPossibleState(State<Node>*,State<Node>*)|		 	   		  	  	^    
|___________________________________________________________________| ________________________|______________________________    
					  ^											  	 |TraceBackSearcher: Searche<T,vector<State<T>*>>			|    
	 _________________|__________________________				  	 |_______________________________________________			|    
	| MatrixSearchable:Searchable<pair<int,int>> |				 	 |protected:									  			|    
	|____________________________________________|				  	 |vector<State<T>*> backTrace(State<T>*init, State<T> *goal)|    
	| MatrixSearchable(vector<vector<double>>)	 |				 	 |clearAll(vector<State<T> *> output,DBtoSearcher<T>* DB)	| <>-|    
	|____________________________________________|				 	 |__________________________________________________________|			  |    
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
