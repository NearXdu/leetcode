typedef UndirectedGraphNode Node;
class Solution
{
    private:
	Node * dfs(Node *node);
	unordered_map<Node*,Node*>visit;
    public:
	Node*cloneGraph(Node *node);


};

Node* Solution::dfs(Node * node)
{
    if(visit.find(node)==visit.end())
    {
	visit[node] = new Node(node->label);
	for(int i=0;i<node->neighbors.size();i++)
	{
	    Node *tmp=dfs(node->neighbors[i]);
	    visit[node]->neighbors.push_back(tmp);
	}
    }
    return visit[node];
}
Node *Solution::cloneGraph(Node *node)
{
    if(NULL==node)
	return NULL;
    return dfs(node);

}
