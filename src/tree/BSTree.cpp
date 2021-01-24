// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

// https://www.luogu.com.cn/problem/P5076
// wrong answer

#include <memory>
#include <optional>

template<typename T>
class BSTree {
    struct Node {
        T elem;
        unsigned int tree_size, node_count;
        std::shared_ptr<Node> left, right;
        explicit Node(T elem) : elem(elem), tree_size(1), node_count(1), left(nullptr), right(nullptr) {}
    };
    std::shared_ptr<Node> root;

public:
    BSTree() : root(nullptr) {}
    void insert(T elem) {
        std::shared_ptr<Node> *cur_node = &root;
        while (*cur_node != nullptr) {
            ++(*cur_node)->tree_size;
            const auto &node_elem = (*cur_node)->elem;
            if (node_elem == elem) {
                ++(*cur_node)->node_count;
                break;
            } else if (elem < node_elem) {
                cur_node = &(*cur_node)->left;
            } else {
                cur_node = &(*cur_node)->right;
            }
        }
        if (*cur_node == nullptr) {
            *cur_node = std::make_shared<Node>(elem);
        }
    }

    unsigned int size() {
        return root == nullptr ? 0 : root->tree_size;
    }

    T prev(T elem) {
        auto cur_node = root;
        T max_prev = elem;
        while (cur_node != nullptr) {
            if (cur_node->elem < elem) {
                max_prev = cur_node->elem;
                cur_node = cur_node->right;
            } else {
                cur_node = cur_node->left;
            }
        }
        return max_prev;
    }

    T succ(T elem) {
        auto cur_node = root;
        T min_succ = elem;
        while (cur_node != nullptr) {
            if (cur_node->elem > elem) {
                min_succ = cur_node->elem;
                cur_node = cur_node->left;
            } else {
                cur_node = cur_node->right;
            }
        }
        return min_succ;
    }

    unsigned int get_rank_by_value(T elem) {
        unsigned int rank = 1;
        std::shared_ptr<Node> cur_node = root;
        while (cur_node != nullptr) {
            if (cur_node->elem > elem) {
                rank += cur_node->tree_size;
                if (cur_node->left == nullptr) {
                    return rank;
                }
                cur_node = cur_node->left;
                rank -= cur_node->tree_size;
            } else {
                if (cur_node->right == nullptr) {
                    return rank;
                }
                cur_node = cur_node->right;
            }
        }
        return rank;
    }

    std::optional<T> get_value_by_rank(unsigned int rank) {
        auto cur_node = root;
        unsigned int cur_rank = 1;
        if (root != nullptr && root->right != nullptr) {
            cur_rank += cur_node->right->tree_size;
        }
        while (cur_node != nullptr) {
            if (cur_rank == rank) {
                return cur_node->elem;
            } else if (cur_rank < rank) {
                if (cur_node->left == nullptr) {
                    return cur_node->elem;
                }
                cur_rank += cur_node->node_count;
                cur_node = cur_node->left;
                if (cur_node->right != nullptr) {
                    cur_rank += cur_node->right->tree_size;
                }
            } else {
                if (cur_node->right == nullptr) {
                    return cur_node->elem;
                }
                cur_node = cur_node->right;
                cur_rank -= cur_node->node_count;
            }
        }
        return std::optional<T>();
    }
};

int main() {
    std::shared_ptr<BSTree<int>> tree = std::make_shared<BSTree<int>>();
    int q;
    scanf("%d", &q);
    while (q--) {
        int op, num, res;
        scanf("%d %d", &op, &num);
        switch (op) {
        case 1:
            printf("%u\n", tree->get_rank_by_value(num));
            break;
        case 2:
            printf("%d\n", tree->get_value_by_rank(num).value_or(INT32_MAX));
            break;
        case 3:
            res = tree->prev(num);
            printf("%d\n", res == num ? INT32_MIN + 1 : res);
            break;
        case 4:
            res = tree->succ(num);
            printf("%d\n", res == num ? INT32_MAX : res);
            break;
        case 5:
            tree->insert(num);
        default:
            break;
        }
    }
    return 0;
}