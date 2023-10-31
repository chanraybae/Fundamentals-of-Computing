/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 10/29/2021
 * File Contents: This file contains the code for the merge K sorted lists leetcode problem by priorty queue
 */

// Leetcode given definition code block
struct ListNode {
     int val;
     ListNode *next;
	 ListNode() : val(0), next(nullptr) {}
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {		
	public:
	    	
		ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode* root = nullptr, *p = nullptr;
    	priority_queue <pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > q;
    	for (auto i = 0; i < lists.size(); ++i) 
        	if (lists[i] != nullptr) q.push({lists[i]->val, lists[i]});
    	while (!q.empty()) {
        	if (root == nullptr) root = p = q.top().second;
        	else p = p->next = q.top().second;
        	q.pop();
        	if (p->next != nullptr) q.push( {p->next->val, p->next });
    	}
    	return root;
		}
};
