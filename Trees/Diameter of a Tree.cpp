// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/?envType=daily-question&envId=2024-12-24
//subquestion of this problem ws to find the diameter of tree


// my Approach
int dia(int nd, int par) {
    int mx1 = 0, mx2 = 0;
    for (auto& ch : tree[nd]) {
        if (ch == par) continue;
        int v = dia(ch, nd);
        if (v > mx1) {
            mx2 = mx1;
            mx1 = v;
        }
        else if(v > mx2) mx2 = v;
    }
    diameter = max(d1, mx1 + mx2);      //diameter a global variable
    return mx1+1;
}

Approach 2: Depth First Search
    Intuition
    Let’s start with a simple observation based on the definition of the diameter:

    For each node in the tree, we calculate the length of the longest path passing through it. The longest of these paths represents the diameter of the tree.
    To determine the longest path that passes through a node u, we perform a DFS to calculate the two longest distances from u to any leaf nodes in the tree.
    The sum of these two distances gives the length of the longest path through u.

    During the recursive calls, each node returns two values:

    The diameter of its subtree.
    The longest path to a leaf in its subtree, or its depth. This avoids redundant calculations, reusing previously computed values.



Approach 1: Farthest of Farthest (BFS)
    Intuition
    Let's break down the problem of calculating the diameter of a tree. First of all, we observe that any tree can be seen as:

    The sequence of nodes on the diameter itself, plus
    Additional subtrees branching out from nodes along the diameter.
    Tree = sequence of nodes on the diameter + subtrees
    For any node in the tree, its minimum distance to one of the diameter's endpoints (say a and b) is always less than or equal to the diameter. This can be proven via contradiction. If one endpoint of the diameter (a) is known, the other endpoint (b) is simply the farthest node from a.

    Based on that, one naive way to find the diameter is:

    Assume each node is one endpoint of the diameter.
    Calculate the farthest node from it.
    Record the longest path found.
    However, this approach involves computing the farthest node for all nodes, leading to a time complexity of O(n
    2
     ), which will result in a TLE (Time Limit Exceeded) for the given constraints.

    For the optimized approach, we observe that we only need to find the farthest node of a single arbitrary node u and that node would be one of the endpoints of the diameter. Why does this work? Let's consider the following cases:

    Case 1: u lies on the diameter
    Running a BFS for the longest path from u will find an endpoint of the diameter.
    We will prove this statement by contradiction. Let v (v not equal a,b) be the farthest node from u, implying dist(u,b)<dist(u,v). Assume u is closer to a than b, so dist(u,a)≤dist(u,b). Combining these inequalities gives us:
    dist(u,b) + dist(u,a) < dist(u,v) + dist(u,b)
    dist(a,b) <  dist(v,b)
    which is a contradiction, since the diameter (a→b) is the longest path in the tree.

    Case 2: u does not lie on the diameter
    The path from u to the farthest node passes through the diameter so the problem reduces to Case 1.

    Let v (v not equal a,b) be the farthest node from u, and u* the root of u's subtree. The path u→v avoids the diameter only if u and v are within the same subtree. In this case:

    dist(u,v) > dist(u,b)
    dist(u,u*)+dist(u*,v) ≥ dist(u,u*)+dist(u*,b)
    dist(u*,v) > dist(u*,b)
    dist(a,u*)+dist(u*,v) ≥ dist(a,u*)+dist(u*,b)
    dist(a,v) > dist(a,b)
    which is a contradiction, since the diameter (a→b) is the longest path in the tree.

    Therefore, to calculate the diameter of a tree, only two BFS calls are needed:

    First BFS starting from any arbitrary node to find the farthest node from it, which is also an endpoint of the diameter.
    Second BFS starting from this farthest node to find the farthest node from it, which is equal to the second endpoint of the diameter.




//app3 - related question - https://leetcode.com/problems/minimum-height-trees/submissions/1490080171/
Approach 3: Topological Sorting
    Intuition
    First, observe that the diameter endpoints must be leaves, as any non-leaf endpoints would allow the diameter to extend further in the opposite direction, contradicting the definition of the diameter.

    Therefore, removing all leaves reduces the diameter by 2, and the remaining diameter becomes the diameter of the reduced tree. As a result, the remaining part of the diameter will still be the diameter of the reduced tree.

    If we continue removing the leaves, the remaining diameter will get progressively smaller until only one or two nodes are left.

    If one node is left, the diameter equals the number of nodes removed during the reduction.
    If two nodes remain, we count the edge connecting them as part of the diameter.
    To track the current leaves of the reduced tree, we will update the counters of their neighboring nodes, also known as the degree of each node.
    Once a node's degree reaches 1, we will enqueue that node in the nodesQueue for further processing.
