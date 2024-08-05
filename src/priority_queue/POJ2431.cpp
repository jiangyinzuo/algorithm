#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
	int distance;
	int fuels;
	bool operator < (const Node &node) const
	{
		return distance > node.distance;
	}
}stops[10009];

priority_queue<int> pQueOfFuels;

int main()
{
	int numOfStops, distanceToTown, remainedFuels;
	scanf("%d", &numOfStops);
	for (int i = 0; i < numOfStops; i++) {
		scanf("%d%d", &stops[i].distance, &stops[i].fuels);
	}
	scanf("%d%d", &distanceToTown, &remainedFuels);
	sort(stops, stops + numOfStops);

	int i = 0, timesOfAcquireFuels= -1;
	pQueOfFuels.push(remainedFuels);
	while(distanceToTown>0 && !pQueOfFuels.empty()){
		distanceToTown -= pQueOfFuels.top();
		pQueOfFuels.pop();
		timesOfAcquireFuels++;
		while(stops[i].distance >= distanceToTown && i<numOfStops){
			pQueOfFuels.push(stops[i++].fuels);
		}
	}

	if (distanceToTown<=0) printf("%d\n", timesOfAcquireFuels);
	else printf("-1\n");
	return 0;
}
