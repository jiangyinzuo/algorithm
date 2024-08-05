#include<cstdio>
#include<algorithm>
using namespace std;
class Node{
public:
    static int total;
    int length;
    int width;
    int height;
    bool operator<(const Node &node) const {
        if(width==node.width) return length < node.length;
        return width < node.width;
    }
    bool operator>(const Node &node) const {
        return length > node.length && width > node.width;
    }
};

int Node::total = 0;
Node block[183];
int dimensions[3];

void addBlock()
{
    block[Node::total].height = dimensions[0];
    block[Node::total].length = max(dimensions[1], dimensions[2]);
    block[Node::total].width = min(dimensions[1], dimensions[2]);
    ++Node::total;
    if(dimensions[1]!=dimensions[0]){
        block[Node::total].height = dimensions[1];
        block[Node::total].length = max(dimensions[2], dimensions[0]);
        block[Node::total].width = min(dimensions[2], dimensions[0]);
        ++Node::total;
    }
    if(dimensions[2]!=dimensions[1] && dimensions[2]!=dimensions[0]){
        block[Node::total].height = dimensions[2];
        block[Node::total].length = max(dimensions[0], dimensions[1]);
        block[Node::total].width = min(dimensions[0], dimensions[1]);
        ++Node::total;
    }
}

int maxHeightOfBlock[183];

int dynamicProgramming()
{
    maxHeightOfBlock[0] = block[0].height;
    for(int i=1;i<Node::total;i++){
        maxHeightOfBlock[i] = block[i].height;
        for(int j=i-1;j>=0;j--){
            if(block[i] > block[j] && maxHeightOfBlock[i] < maxHeightOfBlock[j]+block[i].height){
                maxHeightOfBlock[i] = maxHeightOfBlock[j] + block[i].height;
            }
        }
    }
    int maxHeight = 0;
    for(int i=0;i<Node::total;i++){
        maxHeight = max(maxHeight, maxHeightOfBlock[i]);
    }
    return maxHeight;
}

int main()
{
    int num, testCase = 1, ans;
    while(1){
        Node::total = 0;
        scanf("%d",&num);
        if(num==0) break;
        for(int i=0;i<num;i++){
            scanf("%d%d%d",&dimensions[0],&dimensions[1],&dimensions[2]);
            addBlock();
        }
        sort(block, block+Node::total);
        ans = dynamicProgramming();
        printf("Case %d: maximum height = %d\n", testCase, ans);
        testCase++;
    }
    return 0;
}
