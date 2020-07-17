#include<iostream>
#include<unordered_map>
using namespace std;
 struct DLL
{
	int key;
	int value;
	struct DLL *prev;
	struct DLL *next;
} ;

class LRUCache
{
public:
	int get(int key);
	void put(int key, int value);
	LRUCache(int capacity);

	//add node in DLL;
	void addNode(DLL *node);
	void removeNode(DLL *node);
	void moveToHead(DLL *node);
	DLL* popTail();
	void printList();

private:
	int _capacity,  size;
	std::unordered_map <int, struct DLL*> _cache;
	DLL *head, *tail;
    typedef unordered_map <int, struct DLL*> TNodeMap;
};

void LRUCache::printList()
{
	struct DLL* last;
	struct DLL* first = tail;
	printf("\nTraversal in forward direction \n");  
	while (first != NULL) {  
		printf(" %d ", first->key);  
		last = first;  
		first = last->prev;  
	}  
	if(tail!= NULL)
	{
		printf("tail %d ", tail->key);  
	}
}
void LRUCache::addNode(DLL *node)
{
	/**
	* Always add the new node right after head.
	*/
    if(head == nullptr)
    {
        head = node;
		tail = node;
    }
    else
    {
        head->prev = node;
        node->next = head;
        head = node;
		//shead->prev = nullptr;
    }
}

void LRUCache::removeNode(DLL *node)
{
	 if (node->prev != nullptr)
		node->prev->next = node->next;
	if (node->next != nullptr)
		node->next->prev = node->prev;
}

void LRUCache::moveToHead(DLL *node)
{	
	if (node != head) 
	{
		//If at tail, update tail
		if (node == tail) 
		{
			tail = node->prev;
		}
		removeNode(node);
		addNode(node);
	}
}

DLL* LRUCache::popTail()
{
    if(tail == nullptr)
    {
        return nullptr;
    }
    else
    {
        DLL* res = tail;
       // removeNode(res);
        return res;
    }
}


LRUCache::LRUCache(int capacity)
{
	_capacity = capacity;
	size = 0;
	 
	head = nullptr;
    // head.prev = null;

	tail = nullptr;
}

void LRUCache::put(int key, int value)
{
	std::unordered_map <int, struct DLL*>::iterator it = _cache.find(key);
	if(it != _cache.end())
	{
		DLL *node = it->second;
		node->value = value;
		moveToHead(node);
	}
	else
	{
		++size;
		if(size>_capacity)
		{
			DLL* tailNode = tail;
			if(tailNode!= nullptr)
			{
				_cache.erase(_cache.find(tailNode->key));
				//Remove LRU item from list
				DLL *tmp = tailNode;
				if (head == tail) 
				{
					head = nullptr;
					tail = nullptr;
				}
				else
				{
					tail = tail->prev;
					if(tail)
					{
						tail->next = nullptr;

					}
				}
				--size;
				free(tailNode);
			}
		}
		struct DLL *newNode = (struct DLL*)malloc(sizeof(struct DLL));
		newNode->next = nullptr;
		newNode->prev =  nullptr;
		newNode->value = value;
		newNode->key = key;
		_cache.insert(TNodeMap::value_type(key, newNode));
		addNode(newNode);

	}
}

int LRUCache::get(int key)
{
	std::unordered_map <int, struct DLL*>::iterator it = _cache.find(key);
	if(it == _cache.end())
	{
		return -1;
	}
	DLL *node = it->second;
	// move the accessed node to the head;
	moveToHead(node);
	return node->value;
}
/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/
int main12()
{
	LRUCache *lruCache = new LRUCache(2);
	lruCache->put(1,1);
	lruCache->put(2,2);
	lruCache->get(1);
	lruCache->put(3,3);
	lruCache->get(2);
	lruCache->put(4,4);
	lruCache->get(1);
	lruCache->get(3);
	lruCache->get(4);

	//lruCache->printList();

	/*["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
*/
	return 0;
}
