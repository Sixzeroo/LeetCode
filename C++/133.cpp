/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// BFS 格式上比较难处理
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        
        map<UndirectedGraphNode*, bool> isused;
        map<UndirectedGraphNode*, UndirectedGraphNode*> res;
        
        queue<UndirectedGraphNode*> que;
        res[node] = root;
        que.push(node);
        
        UndirectedGraphNode* curNode;
        UndirectedGraphNode* newNode;
        UndirectedGraphNode* childNode;
        while(!que.empty())
        {
            curNode = que.front();
            que.pop();
            
            if(isused[curNode]) continue;
            
            newNode = res[curNode];
            isused[curNode] = true;
            for(int i = 0; i < (curNode->neighbors).size(); i++)
            {
                childNode = curNode->neighbors[i];
                if(!res[childNode])
                {
                    UndirectedGraphNode* temNode = new UndirectedGraphNode(childNode->label);
                    res[childNode] = temNode;
                }
                newNode->neighbors.push_back(res[childNode]);
                que.push(childNode);
            }
        }
        
        return root;
    }
};