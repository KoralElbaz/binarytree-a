#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

//BinaryTree<int> tree_of_ints;

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

BinaryTree<Color> binary_tree_color_generator()
{
    BinaryTree<Color> bt;
    bt.add_root(Color("pink"))
        .add_left(Color("pink"), Color("blue"))
        .add_left(Color("blue"), Color("orange"))
        .add_right(Color("blue"), Color("green"))
        .add_right(Color("pink"), Color("red"))
        .add_left(Color("pink"), Color("yellow"));
    return bt;
      /* Prints the tree in a reasonable format. For example:
        pink
        |-------------|
        yellow       red
        |-------------|
        orange      green
  */
}


//---------------------------------------  int  --------------------------------------------//
TEST_CASE("check preorder by int")
{
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1);
    for (int i = 1; i < 10; i++) {
        tree_of_ints.add_left(i, i + 1);
    }
    int j = 1;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder() || j<10; it++,j++) {
                CHECK((*it) == j);
       
    }
}

TEST_CASE("check preorder by int")
{
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1);

    for (int i = 1; i < 10; i++) {
        tree_of_ints.add_right(i, i + 1);
    }
    int j = 1;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder() || j<10; it++,j++) {
                CHECK((*it) == j);
       
    }
}


//--------------------------------------- object Color --------------------------------------------//

TEST_CASE("check preorder by object")
{
    BinaryTree<Color> tree_of_color = binary_tree_color_generator();

    Color arr_colors[] = {Color("pink"), Color("yellow"), Color("orange"), Color("green"), Color("red")};
    int j = 0;
    for (auto it = tree_of_color.begin_preorder(); it != tree_of_color.end_preorder() && j < 5; ++it, j++)
    {
        CHECK((*it) == arr_colors[j]);
    }
}

TEST_CASE("check inorder by object")
{
    BinaryTree<Color> tree_of_color = binary_tree_color_generator();

    Color arr_colors[] = {Color("orange"), Color("yellow"), Color("green"), Color("pink"), Color("red")};
    int j = 0;
    for (auto it = tree_of_color.begin_preorder(); it != tree_of_color.end_preorder() && j < 5; ++it, j++)
    {
        CHECK((*it) == arr_colors[j]);
    }
}

TEST_CASE("check postorder by object ")
{
    BinaryTree<Color> tree_of_color = binary_tree_color_generator();

    Color arr_colors[] = {Color("orange"), Color("green"), Color("yellow"), Color("red"), Color("pink")};
    int j = 0;

    for (auto it = tree_of_color.begin_preorder(); it != tree_of_color.end_preorder() && j < 5; ++it, j++)
    {
        CHECK((*it) == arr_colors[j]);
    }
}


TEST_CASE("change the int tree ")
{
    BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(1));

    CHECK_NOTHROW(tree_of_ints.add_left(1, 2));
    CHECK_NOTHROW(tree_of_ints.add_right(1, 3));

    CHECK_NOTHROW(tree_of_ints.add_left(2, 4));
    CHECK_NOTHROW(tree_of_ints.add_right(2, 5));

    CHECK_NOTHROW(tree_of_ints.add_left(3, 6));
    CHECK_NOTHROW(tree_of_ints.add_right(3, 7));

    CHECK_NOTHROW(tree_of_ints.add_right(5, 3));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 9));

    CHECK_THROWS(tree_of_ints.add_right(10, 11)); // 10 not in the tree
    CHECK_THROWS(tree_of_ints.add_left(12, 4)); // 12 not in the tree
    CHECK_THROWS(tree_of_ints.add_left(2, 18)); // 2 not in the tree 

}

TEST_CASE("change the char tree")
{
    BinaryTree<char> tree_of_char;
    CHECK_NOTHROW(tree_of_char.add_root('r'));
    CHECK_NOTHROW(tree_of_char.add_right('r', 'h'));
    CHECK_NOTHROW(tree_of_char.add_right('h', 'y'));

    CHECK_NOTHROW(tree_of_char.add_left('r', 'f'));
    CHECK_NOTHROW(tree_of_char.add_left('f', 'g'));

    CHECK_NOTHROW(tree_of_char.add_right('f', 'b'));
   
    CHECK_NOTHROW(tree_of_char.add_right('y', 's'));
 
    CHECK_NOTHROW(tree_of_char.add_left('s', 'a'));
    CHECK_THROWS(tree_of_char.add_right('z', 'g'));

    CHECK_THROWS(tree_of_char.add_left('q', 'a'));
    CHECK_NOTHROW(tree_of_char.add_root('n'));

    CHECK_THROWS(tree_of_char.add_right('p', 'y')); // p not in the tree
    CHECK_THROWS(tree_of_char.add_left('l', 'a'));// l not in the tree

}