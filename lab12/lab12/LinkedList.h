// Header file for linked list class

template<class T>
class LinkedList{
public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	LinkedList(); //default construtor
	LinkedList(const LinkedList& lst); //copy constructor
	/* Every class should have a destructor, which is responsible for
	 * cleaning  up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~LinkedList();//destructor
	
	// PRE:
	// POST: A new node containing the given data is inserted at the front
	//       of the list
	// PARAM: data is the data to be stored
	void add(T data);

	// PRE:
	// POST: A new node containing the given data is inserted at the given
	//       position in the list
	// PARAM: pos specifies the (index) position to insert the new node
	//        data is the data to be stored
	void insertAt(T pos, T data);
	
	// PRE:
	// POST: The first incidence of the given data is removed from the list.
	//       Returns true if data is found (and removed), false otherwise
	// PARAM: data specifies the data to be removed from the list
	bool remove(T data );
	
	// PRE:
	// POST: Empties the list, freeing up dynaically allocated memory
	// PARAM: 
	void removeAll();

	// PRE:
	// POST: Prints the contents of the list to the screen, in order
	// PARAM:
	void printList();

private:
	/* A struct contains data variable (which are accessed using dot
	 * notation in the same way that object methods or attributes are
	 * accessed).  Structs cannot have methods.*/
	// List node
	struct Node {
		T data; //list data
		Node *next; //pointer to next item in the list
	};

	Node *head; //Pointer to the first node in the list
	T size; //Records the number of nodes in the list
};
template<class T>
class set:public LinkedList<T>{
	public:
		void insert(T a);
		bool contains(T item);
};


