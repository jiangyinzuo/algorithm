//
// Created by Jiang Yinzuo on 2021/1/20.
//

#include <queue>
#include <bitset>

/**
 * 既能让队头出队，又能让队中的最值出队的队列
 * @tparam T 队列元素类型
 * @tparam MAX_N
 * @tparam compare
 */
template<typename T, std::size_t MAX_N, typename compare = std::greater<unsigned long long>>
class HeapQueue {
	struct Pair {
		T elem{};
		unsigned long long order{};

		bool operator<(const Pair &p) const {
			return elem < p.elem || elem == p.elem && compare()(order, p.order);
		}

		Pair(T elem, std::size_t order) : elem(elem), order(order) {};
		Pair() = default;
	};

private:
	unsigned long long idx = 1;
	std::priority_queue<Pair> p_queue;
	std::queue<T> queue;
	unsigned long long queue_next_pop_idx = 0;
	std::bitset<MAX_N> popped;
public:
	void push(T elem) {
		queue.push(elem);
		p_queue.emplace(elem, idx);
		++idx;
	}

	Pair pop_first() {
		T first;
		do {
			first = queue.front();
			queue.pop();
		} while (popped[++queue_next_pop_idx]);
		popped[queue_next_pop_idx] = true;
		return {first, queue_next_pop_idx};
	}

	Pair pop_top() {
		Pair top;
		do {
			top = p_queue.top();
			p_queue.pop();
		} while (popped[top.order]);
		popped[top.order] = true;
		return top;
	}
};

#include <cstdio>

int main() {
	HeapQueue<int, 500000> h;
	int q;
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		switch (op) {
			case 1:
				int elem;
				scanf("%d", &elem);
				h.push(elem);
				break;
			case 2:
				printf("%llu ", h.pop_first().order);
				break;
			case 3:
				printf("%llu ", h.pop_top().order);
				break;
			default:
				break;
		}
	}
	return 0;
}