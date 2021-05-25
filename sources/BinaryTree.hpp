#pragma one
#include <memory>

//std::shared_ptr<Node>
namespace ariel
{

    //--------------------------------------- Node class -------------------------------------//
    template <typename T>
    class BinaryTree
    {
        class Node
        {
            friend class BinaryTree;
            T data;
            Node *left;
            Node *right;
            Node *parent;
            Node(T val) : data(val), right(NULL), left(NULL), parent(NULL){};
        };

        Node *root;

    public:
        BinaryTree() : root(nullptr) {}
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree)
        {
            return os;
        }
        BinaryTree<T> &add_root(T data)
        {
            if (root != nullptr) // There is already a root just need to update a value
            {
                root->data = data;
            }
            else // We will create a new one
            {
                this->root = new Node(data);
            }
            return *this;
        }

        Node *found_node(Node *node, T value)
        {
            if (node == nullptr) //Basic
            {
                return nullptr;
            }
            if (node->data == value) // we found the value !!!!!
            {
                return node;
            }
            Node *right_node = nullptr;
            Node *left_node = nullptr;
            if (node->left != nullptr) // if we can move left
            {
                left_node = found_node(node->left, value);
            }
            if (node->right != nullptr) // if we can move right
            {
                right_node = found_node(node->right, value);
            }
            // If the tree is not symmetrical
            if (left_node != nullptr)
            {
                return left_node;
            }
            else
            {
                return right_node;
            }
        };

        // Node *find_node(T value){
        //     if(root->value==value)
        //     {
        //         return root;
        //     }
        //     return find_node(root,val);
        // };

        BinaryTree<T> &add_left(T parent_val, T child_val)
        {
            Node *found = found_node(this->root, parent_val);
            if (found == nullptr) // if we didnt found
            {
                throw std::invalid_argument("No value found");
            }
            else
            {
                if (found->left == nullptr) //If he has no left son
                {
                    found->left = new Node(child_val);
                    found->left->parent = found; // Updating his parent
                }
                else // If he has a son
                {
                    found->left->data = child_val;
                }
            }
            return *this;
        }

        BinaryTree<T> &add_right(T parent_val, T child_val)
        {
            Node *found = found_node(this->root, parent_val);
            if (found == nullptr) // if we didnt found
            {
                throw std::invalid_argument("No value found");
            }
            else
            {
                if (found->right == nullptr) //If he has no right son
                {
                    found->right = new Node(child_val);
                    found->right->parent = found; // Updating his parent
                }
                else // If he has a son
                {
                    found->right->data = child_val;
                }
            }
            return *this;
        }

        //--------------------------------------- Preorder class -------------------------------------//

        class Preorder_iter
        {
        private:
            Node *curr;

        public:
            Preorder_iter(Node *ptr = nullptr) : curr(ptr){};
            Preorder_iter(): curr(nullptr){}

            T &operator*() const
            {
                return curr->data;
            }

            T *operator->() const
            {
                return &(curr->data);
            }
            Preorder_iter &operator++()
            {
                return *this;
            }
            const Preorder_iter operator++(int)
            {
                return *this;
            }
            bool operator==(const Preorder_iter &other) const
            {
                return false;//curr == other.p_ccurrurr;
            }

            bool operator!=(const Preorder_iter &other) const
            {
                return false;//curr != other.curr;
            }
        };
        //--------------------------------------- Inorder class -------------------------------------//

        class Inorder_iter
        {
        private:
            Node *curr;

        public:
            Inorder_iter(Node *ptr = nullptr) : curr(ptr){};
            Inorder_iter(): curr(nullptr){}


            T &operator*() const
            {
                return curr->data;
            }

            T *operator->() const
            {
                return &(curr->data);
            }
            Inorder_iter &operator++()
            {
                return *this;
            }
            const Inorder_iter operator++(int)
            {
                return *this;
            }
            bool operator==(const Inorder_iter &other) const
            {
                return false;//curr == other.p_ccurrurr;
            }

            bool operator!=(const Inorder_iter &other) const
            {
                return false;//curr != other.curr;
            }
        };

        //--------------------------------------- Postorder class -------------------------------------//

        class Postorder_iter
        {
        private:
            Node *curr;

        public:
            Postorder_iter(Node *ptr = nullptr) : curr(ptr){};
            Postorder_iter():curr(nullptr){}


            T &operator*() const
            {
                return curr->data;
            }

            T *operator->() const
            {
                return &(curr->data);
            }
            Postorder_iter &operator++()
            {
                return *this;
            }
            const Postorder_iter operator++(int)
            {
                return *this;
            }
            bool operator==(const Postorder_iter &other) const
            {
                return false;//curr == other.p_ccurrurr;
            }

            bool operator!=(const Postorder_iter &other) const
            {
                return false;//curr != other.curr;
            }
        };

        //--------------------------------------- Tree class -------------------------------------//

        // void push(T data)
        // {
        //     auto temp = make_shared<Node>();
        //     temp->data = data;
        // }

        Inorder_iter begin()
        {
            return begin_inorder();
        };
        Inorder_iter end()
        {
            return end_inorder();
        };
        Preorder_iter end_preorder()
        {
            return Preorder_iter(nullptr);
        }
        Preorder_iter begin_preorder()
        {
            return Preorder_iter(root);
        }
        Inorder_iter end_inorder()
        {
            return Inorder_iter(nullptr);
        }
        Inorder_iter begin_inorder()
        {
            return Inorder_iter(root);
        }
        Postorder_iter end_postorder()
        {
            return Postorder_iter(root);
        }
        Postorder_iter begin_postorder()
        {
            return Postorder_iter(nullptr);
        }
    };
}