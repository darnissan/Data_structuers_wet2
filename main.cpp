
// #include "iostream"
// #include "wet2util.h"
// #include "vector"
// #include "worldcup23a2.h"
// using namespace std;

// #define N 5 // (the size of each permutation in Wet2Util.h)
// // Choose the maximal amount of permutations that you want to create and use:
// #define M 10

// // Print the array that present the permutation:
// // Important - move the field "a" in class "permutation_t" (the array. look there, in "wet2util.h") to public!
// void print(const permutation_t &permut);

// // Multiply chosen permutations from the vector:
// permutation_t mult_permutations(const vector<permutation_t> &permutations, int array_of_indexes[], int num_of_permutations);




// int main()
// {
//     // Here you choose the permutations (the spirits):
//     int array[M][N] = {{0, 1, 2, 3, 4},
//                        {1, 0, 3, 4, 2},
//                        {0, 1, 3, 4, 2},
//                        {1, 0, 2, 3, 4},
//                        {4, 1, 2, 3, 0},
//                        {2, 4, 1, 3, 0},
//                        {0, 4, 3, 1, 2},
//                        {0, 1, 2, 4, 3},
//                        {4, 3, 2, 1, 0},
//                        {3, 0, 4, 2, 1}};
//     // Now the code create the permutations and insert them to the voector:
//     vector<permutation_t> spirits;
//     for (int i = 0; i < M; i++)
//     {
//         permutation_t to_pust(array[i]);
//         if (to_pust.isvalid())
//             spirits.push_back(permutation_t(array[i]));
//         else
//         {
//             cout << "spirit " << i << " is not valid: ";
//             print(to_pust);
//             cout << "valid permutation is all the numbers from 0 to 4" << endl;
//         }
//     }

//     /*------------------------
//      * Enter your code here:
//      * (create teams and players, buy teams... use the spirits that yuo created, from the vector "spirits",
//      * and then, choose one spirit (spirit of team or partial-spirit of player that you want to check,
//      * and print it in the function "print".)
//      */
//     world_cup_t *obj = new world_cup_t();
//     obj->add_team(1);
//     obj->add_team(2);
//     obj->add_player(1, 1, permutation_t(array[0]), 1, 1, 1, true);
//     obj->add_player(2, 1, permutation_t(array[1]), 1, 1, 1, true);
//     obj->add_player(3, 2, permutation_t(array[2]), 1, 1, 1, true);


//     //print(/* Enter here spirit (e.g.: with the function "get_partial_spirit", or another method)*/ tmp_player39_->getSpirit());
    
//     /*----------------------
//      * Choose the permutations that you want to multiply and compare with the spirit that you chose before:
//      * (e.g.: if in team 2 the first player has spirit[3] (the 4 spirit in the array and in the vector),
//      * and the second player has spirit[7], and you entered to the function "print" above "get_partial_spirit" of player2,
//      * enter to the array "indexes_array" {3, 7}, and 2 to the last argument of the function "mult_permutations").
//      * Now, check if the 2 permutations that printed to are equal.
//      */
//     int indexes_array[M] = {/*the indexes (in vector "spirits") of the spirits that you want to multiply*/ 2, 3};
//     permutation_t expected_spirit = mult_permutations(spirits, indexes_array, /*num of the permutations to multiply*/ 2);
//     print(expected_spirit);

//     return 0;
// }

// void print(const permutation_t &permut)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << permut.a[i] << ", ";
//     }
//     std::cout << std::endl;
// }

// permutation_t mult_permutations(const vector<permutation_t> &permutations, int array_of_indexes[], int num_of_permutations)
// {
//     permutation_t result = permutation_t::neutral();
//     for (int i = 0; i < num_of_permutations; i++)
//     {
//         result = result * permutations[array_of_indexes[i]];
//     }
//     return result;
// }
// */

#include "iostream"
#include "wet2util.h"
#include "vector"
#include "worldcup23a2.h"
using namespace std;

//     add_team 1
// add_team 2
// add_team 3
// remove_team 3
// add_player 1001 1 2,3,4,5,1 0 15 2 true
// add_player 2001 2 4,3,5,2,1 0 17 1 true
// play_match 1 2
// num_played_games_for_player 1001
// add_player_cards 2001 2
// get_player_cards 2001
// get_team_points 1
// get_ith_pointless_ability 0
// get_partial_spirit 1001
// buy_team 1 2
static const char *StatusTypeStr[] =
    {
        "SUCCESS",
        "ALLOCATION_ERROR",
        "INVALID_INPUT",
        "FAILURE"};

void print(string cmd, StatusType res)
{
    cout << cmd << ": " << StatusTypeStr[(int)res] << endl;
}

template <typename T>
void print(string cmd, output_t<T> res)
{
    if (res.status() == StatusType::SUCCESS)
    {
        cout << cmd << ": " << StatusTypeStr[(int)res.status()] << ", " << res.ans() << endl;
    }
    else
    {
        cout << cmd << ": " << StatusTypeStr[(int)res.status()] << endl;
    }
}

int main()
{
    world_cup_t *obj = new world_cup_t();
    obj->add_team(1);
    obj->add_team(2);
    obj->add_team(3);
    obj->remove_team(3);
    int arr[5] = {1, 2, 3, 4, 0};
    permutation_t p1=permutation_t(arr);

    obj->add_player(1001, 1, p1, 0, 15, 2, true);
    int arr2[5] = {3, 2, 4, 1, 0};
    permutation_t p2=permutation_t(arr2);
    obj->add_player(2001, 2, p2, 0, 17, 1, true);
    obj->play_match(1, 2);
 print("num_played_games_for_player", obj->num_played_games_for_player(1001));
    obj->add_player_cards(2001, 2);
    print("get_player_cards", obj->get_player_cards(2001));
    print("get_team_points", obj->get_team_points(1));
    print("get_ith_pointless_ability", obj->get_ith_pointless_ability(0));
    print("get_partial_spirit", obj->get_partial_spirit(1001));
    obj->buy_team(1, 2);
    delete obj;
    return 0;



}