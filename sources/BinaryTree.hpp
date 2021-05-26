#pragma one
#include <memory>

namespace ariel
{
	//a template parmeter T with an opetinal name (using of the typename)
    template <typename T>
    class BinaryTree
    {
		//NodeClass
        class Node
        {
            friend class BinaryTree;
            T data;
            Node *left, *right, *parent;
            Node(T val) : data(val), right(NULL), left(NULL), parent(NULL){};
        };
        Node *root;


    public:
        BinaryTree() : root(nullptr){}
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree)
        {
            return os;
        }
        BinaryTree<T> &add_root(T data)
        {
			//there is root
            if (root != nullptr)
            {
                root->data = data;
            }
			//create a root
            else 
            {
                this->root = new Node(data);
            }
        return *this;
        }

        Node *found_node(Node *node, T value)
        {
			// there's not a node
            if (node == nullptr) 
            {
                return nullptr;
            }
			//the value founded
            if (node->data == value)
            {
                return node;
            }
			//to start the right and the left node
            Node *right_node = nullptr;
            Node *left_node = nullptr;
			//if we can move to the left side 
            if (node->left != nullptr) 
            {
                left_node = found_node(node->left, value);
            }
            if (node->right != nullptr)
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

        BinaryTree<T> &add_left(T parent_val, T child_val)
        {
            Node *found = found_node(this->root, parent_val);
			//if not found!
            if (found == nullptr)
            {
				//we throw exp that theres no value 
                throw std::invalid_argument("Didn't find a value");
            }
			//if we find
            else
            {
				//if there's no left son
                if (found->left == nullptr)
                {
					//we star a new left node 
                    found->left = new Node(child_val);
					//and here we update his parents
                    found->left->parent = found;
                }
				//if there is a left son
                else
                {
                    found->left->data = child_val;
                }
            }
            return *this;
        }

        BinaryTree<T> &add_right(T parent_val, T child_val)
        {
            Node *found = found_node(this->root, parent_val);
			//if not found
            if (found == nullptr) 
            {
                throw std::invalid_argument("Didn't find a value");
            }
			//if we find
            else
            {
				//if there's no right son
                if (found->right == nullptr)
                {
					//we start a new right node
                    found->right = new Node(child_val);
					//and here we update his parents
                    found->right->parent = found;
                }
				//if there is a right son
                else
                {
                    found->right->data = child_val;
                }
            }
            return *this;
        }

        //PreOrder Class
        class Preorder_iterator
        {
        private:
            Node *n;

        public:
            Preorder_iterator(Node *ptr = nullptr) : n(ptr){};
            Preorder_iterator(): n(nullptr){}

			//operator* with a tempelate T
            T &operator*() const
            {
                return n->data;
            }

			//operator-> with a template T
            T *operator->() const
            {
                return &(n->data);
            }

			//iterator that pointing to some elemnt in a range of elements, has an ability to iterate 
			//through elements of the range using the opertaor ++
            Preorder_iterator &operator++()
            {
                return *this;
            }

            const Preorder_iterator operator++(int)
            {
                return *this;
            }

			//operator==
            bool operator==(const Preorder_iterator &other) const
            {
                return false;
            }

			//operator != 
            bool operator!=(const Preorder_iterator &other) const
            {
                return false;
            }
        };

		//InOrder Class
        class Inorder_iterator
        {
        private:
            Node *n;

        public:
            Inorder_iterator(Node *ptr = nullptr) : n(ptr){};
            Inorder_iterator(): n(nullptr){};

			//operator* with a tempelate T
            T &operator*() const
            {
                return n->data;
            }

			//operator-> with a tempelate T
            T *operator->() const
            {
                return &(n->data);
            }
            
			//iterator that pointing to some elemnt in a range of elements, has an ability to iterate 
			//through elements of the range using the opertaor ++
			Inorder_iterator &operator++()
            {
                return *this;
            }
            const Inorder_iterator operator++(int)
            {
                return *this;
            }

			//operator ==
            bool operator==(const Inorder_iterator &other) const
            {
                return false;
            }
			
			//operator !=
            bool operator!=(const Inorder_iterator &other) const
            {
                return false;
            }
        };

        
		//PostOrder Class
        class Postorder_iterator
        {
        private:
            Node *n;

        public:
            Postorder_iterator(Node *ptr = nullptr) : n(ptr){};
            Postorder_iterator():n(nullptr){}

			//operator* with a tempelate T
            T &operator*() const
            {
                return n->data;
            }

			//operator-> with a tempelate T
            T *operator->() const
            {
                return &(n->data);
            }

			//iterator that pointing to some elemnt in a range of elements, has an ability to iterate 
			//through elements of the range using the opertaor ++
            Postorder_iterator &operator++()
            {
                return *this;
            }
            const Postorder_iterator operator++(int)
            {
                return *this;
            }

			//operator==
            bool operator==(const Postorder_iterator &other) const
            {
                return false;
            }
			
			//operator !=
            bool operator!=(const Postorder_iterator &other) const
            {
                return false;
            }
        };

        //Tree Class
        Inorder_iterator begin()
        {
            return begin_inorder();
        };
        Inorder_iterator end()
        {
            return end_inorder();
        };
        Preorder_iterator end_preorder()
        {
            return Preorder_iterator(nullptr);
        }
        Preorder_iterator begin_preorder()
        {
            return Preorder_iterator(root);
        }
        Inorder_iterator end_inorder()
        {
            return Inorder_iterator(nullptr);
        }
        Inorder_iterator begin_inorder()
        {
            return Inorder_iterator(root);
        }
        Postorder_iterator end_postorder()
        {
            return Postorder_iterator(root);
        }
        Postorder_iterator begin_postorder()
        {
            return Postorder_iterator(nullptr);
        }
    };
}