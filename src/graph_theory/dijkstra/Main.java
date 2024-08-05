
/**
 * hdu 2544
 */
import java.util.Comparator;
import java.util.Scanner;
import java.util.PriorityQueue;

class Vertex {
    int vertexId;
    int distance;
    Vertex(int vertexId, int distance) {
        this.vertexId = vertexId;
        this.distance = distance;
    }
}

class VertexComparator implements Comparator<Vertex> {
    @Override
    public int compare(Vertex v1, Vertex v2) {
        if (v1.distance == v2.distance) {
            return 0;
        } else {
            return v1.distance < v2.distance ? -1 : 1;
        }
    }
}

class Edge {
    int toVertex;
    int weight;
    int prevEdge = 0;
}

public class Dijkstra {
    static int edgeId = 1;

    static int[] firstEdgeIdOfFromVertices = new int[109];

    static Edge[] edges = new Edge[10009];

    static Vertex[] vertices = new Vertex[109];

    private static PriorityQueue<Vertex> queue = new PriorityQueue<>(new VertexComparator());

    private static void dijkstra(int n) {
        boolean[] grid = new boolean[109];
        queue.add(vertices[1]);
        grid[1] = true;

        while (!queue.isEmpty()) {
            Vertex peekVertex = queue.peek();
//            System.out.println(peekVertex.vertexId);
            queue.remove();

            for (int i = firstEdgeIdOfFromVertices[peekVertex.vertexId]; i != 0; i = edges[i].prevEdge) {
                if (!grid[edges[i].toVertex] &&
                        edges[i].weight + peekVertex.distance < vertices[edges[i].toVertex].distance) {
                    vertices[edges[i].toVertex].distance = edges[i].weight + peekVertex.distance;
                    queue.add(vertices[edges[i].toVertex]);
                }
            }
        }

        System.out.println(vertices[n].distance);
    }

    private static void init() {
        for (int i = 0; i < 10009; ++i) {
            edges[i] = new Edge();
        }
        for (int i = 0; i < 109; ++i) {
            vertices[i] = new Vertex(i, 1000000009);
        }
        for (int i = 0; i < 109; ++i) {
            firstEdgeIdOfFromVertices[i] = 0;
        }
        vertices[1].distance = 0;
        queue.clear();
        edgeId = 1;
    }

    private static void addEdge(int startVertex, int endVertex, int weight) {
        edges[edgeId].prevEdge = firstEdgeIdOfFromVertices[startVertex];
        edges[edgeId].toVertex = endVertex;
        edges[edgeId].weight = weight;
        firstEdgeIdOfFromVertices[startVertex] = edgeId++;
    }

    public static void main(String[] args) {
        int n, m;
        Scanner scanner = new Scanner(System.in);
        while (true) {
            init();

            n = scanner.nextInt();
            m = scanner.nextInt();
            if (n == 0 && m == 0) {
                break;
            }

            int v1, v2, weight;
            for (int i = 0; i < m; ++i) {
                v1 = scanner.nextInt();
                v2 = scanner.nextInt();
                weight = scanner.nextInt();
                addEdge(v1, v2, weight);
                addEdge(v2, v1, weight);
            }

//            for (int startV = 1; startV <= n; ++startV) {
//                for (int i = firstEdgeIdOfFromVertices[startV]; i != 0; i = edges[i].prevEdge) {
//                    System.out.printf("%d %d %d\n", startV, edges[i].toVertex, edges[i].weight);
//                }
//            }
            dijkstra(n);
        }
        scanner.close();
    }
}