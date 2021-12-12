class Tree
{
	private:
	
		struct Node
		{
			int m_datum;
			Node* mp_left;
			Node* mp_right;
		};
		Node* mp_root;
	
	public:
        
		void Insert(int[] arr, int data);
		Node* Search(int data);
		Node* Search_Del(int data)
		void Delete(int data);
		void Traverse(Node* mp_root);
		Node* findmin(Node* temp);
		Node* findmax(Node* temp);
		bool IsEmpty();
};
