#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

class Color
{
public:
    string color_name;
    Color(string c) : color_name(c){};
    bool operator==(const Color &n) const
    {
        return this->color_name == n.color_name;
    };
};

BinaryTree<Color> BT_WithColor()
{
    BinaryTree<Color> bt;
    bt.add_root(Color("pink"))
        .add_left(Color("pink"), Color("blue"))
        .add_left(Color("blue"), Color("orange"))
        .add_right(Color("blue"), Color("green"))
        .add_right(Color("pink"), Color("red"))
        .add_left(Color("pink"), Color("yellow"));
    return bt;
}

//To check preorder by int! but adding in left
TEST_CASE("Int-PreOrder")
{
    BinaryTree<int> intstree;
    intstree.add_root(1);
    for (int i = 1; i < 10; i++) {
        intstree.add_left(i, i+1);
    }
    int j = 2;
    for (auto it = intstree.begin_preorder(); it != intstree.end_preorder() || j<10; it++,j++) {
                CHECK_FALSE((*it) == j);
       
    }
}
//To check preorder by int! but adding in right
TEST_CASE("Int-PreOrder!")
{
    BinaryTree<int> intstree;
    intstree.add_root(1);
    for (int i = 1; i < 10; i++) {
        intstree.add_right(i, i+1);
    }
    int j = 2;
    for (auto it = intstree.begin_preorder(); it != intstree.end_preorder() || j<10; it++,j++) {
                CHECK_FALSE((*it) == j);
       
    }
}

//Object Tests
//To check preorder by object! 
TEST_CASE("Object-PreOrder")
{
    BinaryTree<Color> colortree = BT_WithColor();
    Color arr_colors[] = {Color("Blue"), Color("Black"), Color("White"), Color("Green"), Color("Orange")};
    int j = 0;
    for (auto it = colortree.begin_preorder(); it != colortree.end_preorder() && j < 5; ++it, j++)
    {
        CHECK((*it) == arr_colors[j]);
    }
}

//To check inorder by object!
TEST_CASE("Object-InOrder")
{
    BinaryTree<Color> colortree = BT_WithColor();

    Color arr_colors[] = {Color("White"), Color("Black"), Color("Green"), Color("Blue"), Color("Orange")};
    int j = 0;
    for (auto it = colortree.begin_inorder(); it != colortree.end_inorder() && j < 5; ++it, j++)
    {
        CHECK((*it) == arr_colors[j]);
    }
}

//To check postorder by object!
TEST_CASE("Object-PostOrder")
{
    BinaryTree<Color> colortree = BT_WithColor();

    Color arr_colors[] = {Color("White"), Color("Green"), Color("Black"), Color("Orange"), Color("Blue")};
    int j = 0;

    for (auto it = colortree.begin_postorder(); it != colortree.end_postorder() && j < 5; ++it, j++)
    {
        CHECK((*it) == arr_colors[j]);
    }
}

//To change the int tree!
TEST_CASE("Int-Tree")
{
    BinaryTree<int> intstree;
    CHECK_NOTHROW(intstree.add_root(2));

    CHECK_NOTHROW(intstree.add_left(2, 3));
    CHECK_NOTHROW(intstree.add_right(2, 4));

    CHECK_NOTHROW(intstree.add_left(3, 5));
    CHECK_NOTHROW(intstree.add_right(3, 6));

    CHECK_NOTHROW(intstree.add_left(4, 7));
    CHECK_NOTHROW(intstree.add_right(4, 8));

    CHECK_NOTHROW(intstree.add_right(6, 4));
    CHECK_NOTHROW(intstree.add_left(2, 9));

    // 10 is not in the tree
    CHECK_THROWS(intstree.add_right(10, 11));
    // 12 is not in the tree
    CHECK_THROWS(intstree.add_left(12, 4)); 
    //1 is not in the tree
    CHECK_THROWS(intstree.add_left(1, 18));

}

//To change the char tree
TEST_CASE("Char-Tree")
{
    BinaryTree<char> chartree;
    CHECK_NOTHROW(chartree.add_root('r'));
    CHECK_NOTHROW(chartree.add_right('r', 'h'));
    CHECK_NOTHROW(chartree.add_right('h', 'y'));

    CHECK_NOTHROW(chartree.add_left('r', 'f'));
    CHECK_NOTHROW(chartree.add_left('f', 'g'));

    CHECK_NOTHROW(chartree.add_right('f', 'b'));
   
    CHECK_NOTHROW(chartree.add_right('y', 's'));
 
    CHECK_NOTHROW(chartree.add_left('s', 'a'));
    CHECK_THROWS(chartree.add_right('z', 'g'));

    CHECK_THROWS(chartree.add_left('q', 'a'));
    CHECK_NOTHROW(chartree.add_root('n'));

    // p is not in the tree
    CHECK_THROWS(chartree.add_right('p', 'y')); 
    // l is not in the tree
    CHECK_THROWS(chartree.add_left('l', 'a'));

}
