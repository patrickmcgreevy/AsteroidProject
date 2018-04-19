
#include "ListNode.h"
template <type t>
class AsteroidList {
public:
	AsteroidList();
	~AsteroidList();

	AsteroidNode* getHead();
	void setHead(AsteroidNode* newHead);

	void insertAtFront(AsteroidNode* newNode);

	AsteroidNode* get
private:
	AsteroidNode* pHead;
};