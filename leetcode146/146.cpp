//key---int value---int
struct Node
{
    int key;
    int value;
    struct Node * next;
    struct Node * prev;
};
class LRUCache{
    private:
	vector<Node*>freespace_;
	unordered_map<int,Node*>hashmap_;
	Node*entries_;//
	Node * head_;
	Node * tail_;

	void attach(Node * node)
	{
	    node->next=head_->next;
	    head_->next=node;
	    node->next->prev=node;
	    node->prev=head_;
	}
	void detach(Node *node)
	{
	    node->prev->next=node->next;
	    node->next->prev=node->prev;
	}

    public:
	LRUCache(int capacity) {
	    entries_=new Node[capacity];
	    for(int i= 0;i<capacity;i++)
	    {
		freespace_.push_back(entries_+i);
	    }
	    head_=new Node;
	    tail_=new Node;
	    head_->next=tail_;
	    tail_->prev=head_;
	    head_->prev=NULL;
	    tail_->next=NULL;
	}

	int get(int key) {
	    Node*node=hashmap_[key];
	    if(NULL!=node)
	    {
		detach(node);
		attach(node);
		return node->value;
	    }
	    else
		return -1;
	}

	void set(int key, int value) {
	    Node*node = hashmap_[key];
	    if(NULL!=node)//node exist
	    {
		detach(node);
		node->key=key;
		node->value=value;
		attach(node);
	    }
	    else//not exist
	    {
		//full or not full
		if(freespace_.empty())//full
		{
		    node=tail_->prev;
		    detach(node);
		    hashmap_.erase(node->key);
		    node->key=key;
		    node->value=value;
		    hashmap_[key]=node;
		    attach(node);
		}
		else//not full
		{
		    node = freespace_.back();
		    freespace_.pop_back();
		    node->key=key;
		    node->value=value;
		    hashmap_[key]=node;
		    attach(node);
		}
	    }
	}
};
