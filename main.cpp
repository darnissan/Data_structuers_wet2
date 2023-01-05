
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
#include <stdio.h>
#include <string.h>
#include <sstream>
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
    if (res.status() != StatusType::SUCCESS)
    {
        cout << cmd << ": " << StatusTypeStr[(int)res.status()] << ", " << res.ans() << endl;
    }
    else
    {
        cout << cmd << ": " << StatusTypeStr[(int)res.status()] << endl;
    }
}
template <typename T>
void foo(output_t<T> res)
{
    return;
}
void foo1(StatusType res)
{
    return;
}
std::string str(const permutation_t &perm1)
{
    std::stringstream p1;
    p1 << perm1;
    return p1.str();
}

int main()
{
    world_cup_t wc;

    wc.add_team(21728);
    wc.add_team(64);
    wc.add_team(93992);
    wc.add_player(43922, 64, permutation_t::read("5,4,1,3,2"), 27, 9, 15, false);
    wc.add_team(98255);
    wc.add_player(21524, 58, permutation_t::read("2,3,4,1,5"), 27, 1, 72, false);
    wc.add_player(5351, 64, permutation_t::read("3,2,5,4,1"), 0, 3, 24, false);
    wc.remove_team(64);
    wc.play_match(64, 98255);
    wc.add_player(32376, 21728, permutation_t::read("4,2,3,1,5"), 13, 22, 13, false);
    wc.num_played_games_for_player(32376);
    wc.get_partial_spirit(21524);
    wc.buy_team(21728, 64);
    wc.add_player_cards(21524, 28);
    wc.add_player(70532, 93992, permutation_t::read("2,4,1,3,5"), 27, 25, 1, false);
    wc.get_ith_pointless_ability(3);
    wc.add_player(58179, 93992, permutation_t::read("3,1,2,4,5"), 4, 20, 13, true);
    wc.add_team(19889);
    wc.play_match(19889, 98255);
    wc.add_team(41817);
    wc.get_partial_spirit(70532);
    wc.add_team(65750);
    wc.add_player(55682, 98255, permutation_t::read("4,1,3,2,5"), 19, 22, 45, false);
    wc.add_team(34070);
    wc.remove_team(21728);
    wc.num_played_games_for_player(32376);
    wc.add_player(8566, 98255, permutation_t::read("1,5,3,4,2"), 30, 3, 18, false);
    wc.get_partial_spirit(32376);
    wc.num_played_games_for_player(70532);
    wc.add_player(39017, 34070, permutation_t::read("2,4,1,5,3"), 24, 1, 26, false);
    wc.get_ith_pointless_ability(1);
    wc.add_player(16108, 98255, permutation_t::read("2,5,1,4,3"), 1, 23, 18, false);
    wc.add_player(50730, 41817, permutation_t::read("1,5,3,2,4"), 4, 12, 20, false);
    wc.add_player(85343, 34070, permutation_t::read("4,2,1,3,5"), 18, 23, 28, true);
    wc.add_player(2742, 34070, permutation_t::read("2,4,5,1,3"), 26, 12, 3, false);
    wc.get_partial_spirit(70532);
    wc.get_partial_spirit(58179);
    wc.remove_team(65750);
    wc.play_match(41817, 21728);
    wc.play_match(65750, 93992);
    wc.add_player(2012, 34070, permutation_t::read("5,4,1,2,3"), 2, 27, 20, false);
    wc.add_team(98129);
    wc.add_team(31655);
    wc.add_player(95424, 34070, permutation_t::read("3,2,5,1,4"), 26, 14, 2, false);
    wc.add_team(62416);
    wc.num_played_games_for_player(58179);
    wc.add_team(44765);
    wc.get_partial_spirit(95424);
    wc.add_player(39809, 21728, permutation_t::read("3,4,5,2,1"), 1, 20, 9, true);
    wc.add_player_cards(85343, 15);
    wc.add_player(3921, 64, permutation_t::read("3,1,4,5,2"), 29, 12, 18, true);
    wc.remove_team(98255);
    wc.add_player(69017, 93992, permutation_t::read("5,2,3,1,4"), 22, 18, 12, false);
    wc.get_ith_pointless_ability(10);
    wc.add_player(60200, 93992, permutation_t::read("2,5,3,1,4"), 25, 13, 21, true);
    wc.add_player(16631, 41817, permutation_t::read("5,3,1,4,2"), 12, 8, 19, true);
    wc.add_team(23716);
    wc.add_player(48817, 98129, permutation_t::read("2,5,1,4,3"), 15, 27, 11, false);
    wc.get_ith_pointless_ability(9);
    wc.add_team(70027);
    wc.add_player(61329, 65750, permutation_t::read("4,2,3,1,5"), 28, 19, 29, false);
    wc.get_partial_spirit(58179);
    wc.add_player_cards(39017, 3);
    wc.get_partial_spirit(50730);
    wc.add_player(11941, 98255, permutation_t::read("3,1,5,2,4"), 76, 13, 1, true);
    wc.remove_team(19889);
    wc.get_partial_spirit(48817);
    wc.add_player(64379, 62416, permutation_t::read("2,5,3,1,4"), 16, 12, 30, false);
    wc.add_player(50087, 98255, permutation_t::read("5,1,3,2,4"), 4, 19, 16, false);
    wc.get_partial_spirit(39017);
    wc.add_player(2896, 21728, permutation_t::read("5,2,3,4,1"), 30, 11, 10, false);
    wc.add_player(77900, 62416, permutation_t::read("5,4,1,3,2"), 1, 23, 18, false);
    wc.remove_team(23716);
    wc.add_player(80882, 19889, permutation_t::read("4,2,1,3,5"), 11, 8, 8, false);
    wc.add_team(58527);
    wc.add_player(78725, 19889, permutation_t::read("2,1,3,5,4"), 27, 5, 20, false);
    wc.add_player(95738, 64, permutation_t::read("1,3,2,5,4"), 13, 3, 14, false);
    wc.add_team(92973);
    wc.get_partial_spirit(85343);
    wc.get_team_points(19889);
    wc.add_player_cards(16631, 14);
    wc.add_team(37986);
    wc.buy_team(98255, 44765);
    wc.add_team(988);
    wc.remove_team(988);
    wc.add_player(14373, 31655, permutation_t::read("5,2,4,3,1"), 1, 3, 16, false);
    wc.get_team_points(92973);
    wc.add_player(39138, 64, permutation_t::read("5,3,2,4,1"), 15, 20, 24, false);
    wc.add_team(4);
    wc.num_played_games_for_player(77900);
    wc.play_match(37986, 21728);
    wc.add_player(45691, 58527, permutation_t::read("5,2,1,3,4"), 10, 21, 20, true);
    wc.get_team_points(75);
    wc.add_player(6640, 41817, permutation_t::read("3,1,4,2,5"), 18, 22, 17, false);
    wc.add_team(4);
    wc.add_player(80, 98255, permutation_t::read("4,1,2,5,3"), 18, 30, 21, false);
    wc.add_player(61338, 31655, permutation_t::read("2,1,3,5,4"), 0, 26, 27, false);
    wc.get_partial_spirit(2896);
    wc.get_partial_spirit(2742);
    wc.add_team(0);
    wc.add_team(4);
    wc.remove_team(37986);
    wc.add_player(76560, 23716, permutation_t::read("5,2,4,1,3"), 11, 24, 24, false);
    wc.get_ith_pointless_ability(11);
    wc.add_player(32089, 64, permutation_t::read("2,5,4,1,3"), 12, 25, 1, false);
    wc.add_player(91272, 98255, permutation_t::read("5,3,1,2,4"), 1, 9, 20, false);
    wc.play_match(70027, 19889);
    wc.add_player(47456, 70027, permutation_t::read("1,5,3,4,2"), 0, 19, 28, true);
    wc.add_team(5);
    wc.get_partial_spirit(3921);
    wc.add_player(21311, 23716, permutation_t::read("2,3,1,4,5"), 24, 1, 17, true);
    wc.get_team_points(70027);
    wc.add_team(28668);
    wc.num_played_games_for_player(14373);
    wc.num_played_games_for_player(95738);
    wc.add_team(92617);
    wc.add_player(8320, 34070, permutation_t::read("5,4,1,3,2"), 15, 3, 29, false);
    wc.get_ith_pointless_ability(19);
    wc.add_team(97384);
    wc.play_match(31655, 5);
    wc.add_player(45375, 988, permutation_t::read("5,1,3,4,2"), 7, 13, 9, false);
    wc.add_player(37027, 988, permutation_t::read("4,5,1,3,2"), 5, 9, 23, false);
    wc.get_partial_spirit(77900);
    wc.add_player(4518, 23716, permutation_t::read("1,2,4,3,5"), 15, 7, 28, false);
    wc.get_partial_spirit(4518);
    wc.get_ith_pointless_ability(20);
    wc.get_ith_pointless_ability(4);
    wc.add_player(36023, 34070, permutation_t::read("3,2,4,5,1"), 12, 23, 2, false);
    wc.add_player(99790, 92973, permutation_t::read("4,5,1,2,3"), 15, 18, 23, false);
    wc.add_team(97);
    wc.num_played_games_for_player(37027);
    wc.play_match(97384, 19889);
    wc.get_ith_pointless_ability(18);
    wc.num_played_games_for_player(2896);
    wc.remove_team(65750);
    wc.play_match(31655, 65750);
    wc.add_player(50040, 21728, permutation_t::read("2,1,3,4,5"), 8, 12, 1, true);
    wc.num_played_games_for_player(48817);
    wc.add_player(87815, 23716, permutation_t::read("3,5,1,2,4"), 24, 0, 29, false);
    wc.add_team(21924);
    wc.get_ith_pointless_ability(6);
    wc.add_team(14258);
    wc.play_match(93992, 21924);
    wc.buy_team(19889, 31655);
    wc.num_played_games_for_player(11941);
    wc.add_player(64548, 62416, permutation_t::read("5,3,2,1,4"), 5, 22, 26, false);
    wc.play_match(21924, 37986);
    wc.add_player(59673, 44765, permutation_t::read("2,1,3,5,4"), 2, 0, 21, false);
    wc.add_team(58673);
    wc.add_player(45329, 97, permutation_t::read("4,1,2,3,5"), 0, 27, 26, false);
    wc.add_player_cards(45329, 29);
    wc.add_team(48482);
    wc.add_team(7);
    wc.buy_team(34070, 37986);
    wc.get_ith_pointless_ability(1);
    wc.add_team(48569);
    wc.add_team(20508);
    wc.num_played_games_for_player(3921);
    wc.add_team(77248);
    wc.add_team(57578);
    wc.add_team(71245);
    wc.add_team(35606);
    wc.play_match(48482, 31655);
    wc.add_player(72659, 71245, permutation_t::read("3,5,1,2,4"), 18, 12, 17, true);
    wc.add_team(92967);
    wc.get_partial_spirit(48817);
    wc.add_player(805, 84, permutation_t::read("4,1,3,2,5"), 24, 28, 22, false);
    wc.get_ith_pointless_ability(10);
    wc.add_player(28842, 20508, permutation_t::read("3,2,5,1,4"), 1, 12, 30, true);
    wc.get_partial_spirit(39809);
    wc.num_played_games_for_player(32376);
    wc.play_match(23716, 71245);
    wc.get_ith_pointless_ability(2);
    wc.get_ith_pointless_ability(32);
    wc.add_player(62196, 21924, permutation_t::read("2,4,3,5,1"), 0, 4, 5, false);
    wc.add_player(74316, 48569, permutation_t::read("4,5,3,1,2"), 17, 8, 19, false);
    wc.get_partial_spirit(61329);
    wc.add_player(91233, 19889, permutation_t::read("1,5,2,4,3"), 15, 25, 18, false);
    wc.get_partial_spirit(805);
    wc.get_ith_pointless_ability(24);
    wc.add_player(96369, 65750, permutation_t::read("3,2,4,5,1"), 32, 29, 25, true);
    wc.get_ith_pointless_ability(0);
    wc.add_player(37124, 92617, permutation_t::read("4,3,5,2,1"), 6, 0, 2, false);
    wc.add_player(3402, 31655, permutation_t::read("2,4,1,3,5"), 16, 17, 3, false);
    wc.add_player(54932, 48569, permutation_t::read("5,4,2,1,3"), 7, 23, 12, false);
    wc.num_played_games_for_player(37124);
    wc.add_team(8);
    wc.add_team(2714);
    wc.get_partial_spirit(21311);
    wc.add_team(48718);
    wc.play_match(28668, 20508);
    wc.add_player(32158, 21924, permutation_t::read("4,3,1,2,5"), 19, 19, 5, false);
    wc.add_player_cards(80882, 20);
    wc.get_partial_spirit(62196);
    wc.add_player(81242, 28668, permutation_t::read("2,5,1,3,4"), 23, 17, 17, false);
    wc.add_player(69454, 14258, permutation_t::read("1,5,2,4,3"), 24, 13, 3, false);
    wc.add_player(3133, 41817, permutation_t::read("4,2,1,3,5"), -15, 25, 18, false);
    wc.add_player(78463, 92967, permutation_t::read("4,1,3,2,5"), 10, 24, 24, false);
    wc.add_player(41549, 35606, permutation_t::read("2,1,4,3,5"), 22, 29, 14, false);
    wc.add_player(54, 77248, permutation_t::read("2,1,3,5,4"), 25, 26, 11, true);
    wc.add_player(18232, 31655, permutation_t::read("5,2,1,3,4"), 23, 27, 19, true);
    wc.add_team(13714);
    wc.add_player(25133, 98255, permutation_t::read("1,4,3,5,2"), 75, 26, 26, false);
    wc.add_player(5948, 31655, permutation_t::read("5,4,2,3,1"), 7, 0, 22, false);
    wc.add_player(57995, 97384, permutation_t::read("5,3,2,1,4"), 3, 30, 23, false);
    wc.add_player(77288, 7, permutation_t::read("5,3,4,1,2"), 11, 25, 2, false);
    wc.play_match(23716, 97384);
    wc.add_player(23910, 65750, permutation_t::read("5,2,4,3,1"), 12, 19, 28, true);
    wc.get_team_points(5);
    wc.add_player(69445, 77248, permutation_t::read("5,3,2,1,4"), 30, 17, 25, true);
    wc.add_player(16639, 31655, permutation_t::read("5,2,4,1,3"), 20, 8, 3, false);
    wc.add_player(76813, 71245, permutation_t::read("2,4,3,5,1"), 19, 11, 4, false);
    wc.get_team_points(92973);
    wc.add_team(55585);
    wc.get_partial_spirit(96369);
    wc.add_player(30052, 97384, permutation_t::read("5,2,4,3,1"), 1, 6, 21, false);
    wc.add_team(78270);
    wc.get_partial_spirit(18232);
    wc.add_team(57357);
    wc.add_player(70460, 48718, permutation_t::read("5,3,4,2,1"), 26, 6, 9, true);
    wc.get_ith_pointless_ability(38);
    wc.get_ith_pointless_ability(40);
    wc.add_player(75578, 97, permutation_t::read("4,2,5,3,1"), 14, 11, 10, false);
    wc.add_player(92468, 58673, permutation_t::read("3,5,1,4,2"), 3, 16, 18, true);
    wc.add_player(90566, 58673, permutation_t::read("5,4,1,2,3"), 29, 7, 3, true);
    wc.add_player(19260, 988, permutation_t::read("3,2,4,5,1"), 8, 14, 9, false);
    wc.play_match(37986, 20508);
    wc.play_match(92617, 57357);
    wc.add_team(59352);
    wc.get_partial_spirit(75578);
    wc.add_player(4274, 13714, permutation_t::read("2,4,5,1,3"), 27, 24, 9, false);
    wc.add_team(63411);
    wc.add_player(29485, 48718, permutation_t::read("2,1,3,4,5"), 27, 24, 22, false);
    wc.add_team(91746);
    wc.add_player(74182, 21924, permutation_t::read("1,5,4,3,2"), 1, 20, 21, false);
    wc.add_player(19280, 8, permutation_t::read("4,5,1,3,2"), 30, 15, 12, false);
    wc.get_ith_pointless_ability(6);
    wc.num_played_games_for_player(47456);
    wc.add_player_cards(58179, 27);
    wc.add_player(88417, 92967, permutation_t::read("4,2,5,1,3"), 20, 28, 16, true);
    wc.add_player(64526, 8, permutation_t::read("5,3,4,2,1"), 26, 18, 26, false);
    wc.get_team_points(5);
    wc.add_team(85232);
    wc.add_team(1592);
    wc.num_played_games_for_player(21524);
    wc.add_player(38, 31655, permutation_t::read("5,3,4,2,1"), 9, 15, 14, false);
    wc.add_player(54783, 93992, permutation_t::read("3,2,1,4,5"), 29, 11, 19, false);
    wc.add_player(20873, 1592, permutation_t::read("5,4,3,2,1"), 2, 25, 25, true);
    wc.num_played_games_for_player(21311);
    wc.add_player(46145, 21924, permutation_t::read("1,2,5,3,4"), 16, 23, 25, false);
    wc.num_played_games_for_player(92468);
    wc.add_team(63511);
    wc.get_team_points(34070);
    wc.num_played_games_for_player(47456);
    wc.add_player(81586, 37986, permutation_t::read("5,4,3,1,2"), 14, 26, 25, false);
    wc.add_player(95291, 5, permutation_t::read("4,5,3,2,1"), 30, 11, 30, false);
    wc.get_team_points(2714);
    wc.add_player(23835, 59352, permutation_t::read("3,1,4,5,2"), 26, 19, 16, false);
    wc.remove_team(92617);
    wc.get_partial_spirit(39017);
    wc.add_player(26979, 97, permutation_t::read("1,4,5,2,3"), 17, 26, 23, false);
    wc.buy_team(2714, 48482);
    wc.num_played_games_for_player(11941);
    wc.add_player(34983, 97, permutation_t::read("1,5,4,2,3"), 18, 3, 30, true);
    wc.add_player(53116, 34070, permutation_t::read("1,5,3,4,2"), 3, 29, 13, false);
    wc.num_played_games_for_player(50040);
    wc.add_player(48149, 93992, permutation_t::read("5,1,3,2,4"), 26, 28, 1, false);
    wc.get_partial_spirit(16631);
    wc.play_match(34070, 65750);
    wc.get_team_points(98129);
    wc.add_player_cards(76813, 19);
    wc.num_played_games_for_player(16108);
    wc.num_played_games_for_player(45329);
    wc.get_team_points(78270);
    wc.get_team_points(57357);
    wc.add_player(37103, 1592, permutation_t::read("1,5,3,2,4"), 21, 4, 29, false);
    wc.add_player(54297, 21728, permutation_t::read("3,2,5,1,4"), 23, 2, 36, true);
    wc.add_player(95955, 93992, permutation_t::read("3,1,4,5,2"), 18, 20, 15, true);
    wc.add_player(56655, 48569, permutation_t::read("2,3,1,4,5"), 23, 13, 11, false);
    wc.add_player(1138, 93992, permutation_t::read("5,2,4,1,3"), 26, 2, 14, false);
    wc.remove_team(14258);
    wc.get_team_points(13714);
    wc.add_player_cards(85343, 26);
    wc.remove_team(55585);
    wc.add_player(40971, 21728, permutation_t::read("2,5,3,1,4"), 29, 12, 27, false);
    wc.num_played_games_for_player(54297);
    wc.num_played_games_for_player(78725);
    wc.add_player(11910, 58673, permutation_t::read("3,2,5,1,4"), 30, 3, 25, false);
    wc.add_team(2358);
    wc.play_match(28668, 74);
    wc.add_player(73206, 21924, permutation_t::read("4,2,1,5,3"), 24, 8, 29, false);
    wc.remove_team(64);
    wc.add_team(7);
    wc.play_match(48569, 20508);
    wc.add_player_cards(41549, 24);
    wc.add_player(94943, 92973, permutation_t::read("5,1,3,4,2"), 3, 19, 3, true);
    wc.add_player(5608, 97, permutation_t::read("5,4,2,1,3"), 99, 13, 30, true);
    wc.play_match(97384, 5);
    wc.play_match(48718, 91746);
    wc.get_partial_spirit(90566);
    wc.get_team_points(63411);
    wc.add_player(98540, 8, permutation_t::read("3,1,4,2,5"), 27, 22, 15, false);
    wc.add_player_cards(50040, 9);
    wc.get_partial_spirit(32158);
    wc.get_team_points(65750);
    wc.add_player(65183, 1592, permutation_t::read("4,2,3,1,5"), 11, 22, 14, false);
    wc.remove_team(2358);
    wc.get_ith_pointless_ability(26);
    wc.buy_team(23716, 49);
    wc.add_team(46044);
    wc.remove_team(65750);
    wc.play_match(44765, 65750);
    wc.add_player(75297, 48569, permutation_t::read("5,1,4,2,3"), 0, 27, 6, false);
    wc.get_team_points(57578);
    wc.remove_team(77248);
    wc.add_player(93966, 84, permutation_t::read("2,1,3,4,5"), 2, 17, 26, false);
    wc.add_player(29946, 63411, permutation_t::read("5,3,1,4,2"), 3, 1, 16, false);
    wc.add_player(32910, 37986, permutation_t::read("5,4,1,3,2"), 26, 3, 20, false);
    wc.add_player(76198, 5, permutation_t::read("4,5,2,1,3"), 27, 20, 17, false);
    wc.add_player_cards(60200, 20);
    wc.add_player(24647, 1592, permutation_t::read("3,5,2,4,1"), 21, 18, 9, true);
    wc.add_player(90776, 34070, permutation_t::read("3,2,1,5,4"), 7, 20, 6, true);
    wc.num_played_games_for_player(16108);
    wc.play_match(58673, 37986);
    wc.get_ith_pointless_ability(46);
    wc.add_team(17676);
    wc.get_team_points(2358);
    wc.add_player(93498, 44765, permutation_t::read("3,2,1,4,5"), 23, 4, 10, false);
    wc.play_match(37986, -3);
    wc.add_player(34556, 71245, permutation_t::read("4,2,3,1,5"), 16, 2, 11, true);
    wc.add_player(76958, 7, permutation_t::read("2,4,1,5,3"), 30, 12, 29, false);
    wc.add_player(34429, 64, permutation_t::read("4,5,2,1,3"), 21, 0, 20, false);
    wc.play_match(-16, 37986);
    wc.add_player(51193, 98255, permutation_t::read("1,4,5,3,2"), 20, 7, 24, false);
    wc.add_player(44590, 19889, permutation_t::read("1,2,4,5,3"), 28, 10, 22, false);
    wc.num_played_games_for_player(95955);
    wc.get_team_points(21924);
    wc.remove_team(19889);
    wc.add_player(87512, 37986, permutation_t::read("3,1,5,2,4"), 17, 8, 0, false);
    wc.remove_team(63411);
    wc.add_player(16476, 97, permutation_t::read("5,2,1,3,4"), 9, 8, 15, false);
    wc.add_player(20416, 48482, permutation_t::read("2,3,4,5,1"), 20, 11, 29, false);
    wc.remove_team(77248);
    wc.add_team(94096);
    wc.play_match(71245, 13714);
    wc.get_team_points(41817);
    wc.buy_team(92617, 63511);
    wc.get_ith_pointless_ability(49);
    wc.remove_team(62416);
    wc.add_player(76585, 23716, permutation_t::read("3,4,1,5,2"), -4, 16, 18, false);
    wc.add_player(30749, 8, permutation_t::read("2,5,4,3,1"), 9, 26, 1, false);
    wc.add_team(36920);
    wc.add_player(72871, 21728, permutation_t::read("3,5,4,1,2"), 20, 7, 12, true);
    wc.get_team_points(7);
    wc.add_player(21385, 64, permutation_t::read("1,5,2,4,3"), 13, 6, 15, false);
    wc.add_player(2393, 988, permutation_t::read("5,4,1,2,3"), 7, 5, 14, true);
    wc.add_team(52024);
    wc.get_ith_pointless_ability(50);
    wc.get_partial_spirit(64379);
    wc.add_player(1046, 21728, permutation_t::read("5,4,3,2,1"), 21, 0, 8, true);
    wc.get_team_points(4);
    wc.add_player(97164, 19889, permutation_t::read("2,5,3,4,1"), 24, 1, 21, false);
    wc.add_team(80304);
    wc.add_player(14583, 13714, permutation_t::read("2,3,4,5,1"), 22, 19, 22, false);
    wc.add_player(7922, 64, permutation_t::read("2,3,4,5,1"), 1, 26, 21, true);
    wc.remove_team(48482);
    wc.play_match(7, 21728);
    wc.add_player(82412, 58673, permutation_t::read("2,1,5,3,4"), 5, 27, 22, true);
    wc.add_player(73, 52024, permutation_t::read("3,1,2,5,4"), 8, 30, 7, false);
    wc.add_team(87409);
    wc.add_player(64751, 14258, permutation_t::read("1,4,3,5,2"), 7, 22, 38, false);
    wc.get_ith_pointless_ability(57);
    wc.play_match(7, 97);
    wc.num_played_games_for_player(5608);
    wc.num_played_games_for_player(45329);
    wc.get_partial_spirit(82412);
    wc.remove_team(8);
    wc.num_played_games_for_player(39809);
    wc.add_player(2147, 13714, permutation_t::read("2,5,3,1,4"), 27, 26, 8, false);
    wc.num_played_games_for_player(72871);
    wc.get_partial_spirit(45375);
    wc.buy_team(4, 26);
    wc.add_player(87836, 94096, permutation_t::read("3,5,2,4,1"), 3, 5, 22, false);
    wc.get_team_points(97);
    wc.add_team(3);
    wc.remove_team(97);
    wc.add_team(42255);
    wc.add_player(7938, 71245, permutation_t::read("3,2,5,1,4"), 11, 8, 6, true);
    wc.add_team(45754);
    wc.get_partial_spirit(54932);
    wc.num_played_games_for_player(54932);
    wc.add_player(90498, 48718, permutation_t::read("2,3,5,1,4"), 16, 18, 7, false);
    wc.add_player(39327, 5, permutation_t::read("4,2,1,3,5"), 28, 22, 20, false);
    wc.num_played_games_for_player(90776);
    wc.add_player(87381, 5, permutation_t::read("2,4,5,3,1"), 8, 5, 30, false);
    wc.add_player(23807, 19889, permutation_t::read("2,4,5,3,1"), 27, 13, 10, true);
    wc.add_player(21831, 97, permutation_t::read("4,5,1,3,2"), 30, 19, 4, false);
    wc.add_player_cards(75297, 25);
    wc.add_player(52159, 3, permutation_t::read("4,1,3,2,5"), 13, 7, 8, true);
    wc.get_team_points(2358);
    wc.add_player(3403, 64, permutation_t::read("4,5,2,1,3"), 30, 11, 24, false);
    wc.add_player(86453, 14258, permutation_t::read("3,1,5,2,4"), 17, 2, 9, false);
    wc.get_ith_pointless_ability(31);
    wc.add_player(34326, 64, permutation_t::read("4,1,3,2,5"), 30, 14, 13, false);
    wc.get_partial_spirit(39327);
    wc.add_player(37107, 59352, permutation_t::read("1,2,4,5,3"), 4, 22, 4, true);
    wc.add_player(55322, 92973, permutation_t::read("2,3,4,5,1"), 7, 11, 24, false);
    wc.add_player(3533, 1592, permutation_t::read("2,5,3,4,1"), 6, 26, 20, true);
    wc.get_partial_spirit(29485);
    wc.get_partial_spirit(2896);
    wc.add_player(10835, 4, permutation_t::read("5,2,1,3,4"), 24, 30, 29, true);
    wc.play_match(14258, 92973);
    wc.add_team(30936);
    wc.get_team_points(59352);
    wc.add_player_cards(77900, 23);
    wc.add_player(30139, 58527, permutation_t::read("2,4,1,5,3"), 19, 6, 9, false);
    wc.add_player(94022, 91746, permutation_t::read("3,2,4,1,5"), 0, 18, 18, false);
    wc.remove_team(87409);
    wc.add_team(78450);
    wc.get_partial_spirit(50087);
    wc.get_ith_pointless_ability(56);
    wc.add_player(22673, 92967, permutation_t::read("5,4,1,2,3"), 11, 7, 18, false);
    wc.add_team(5434);
    wc.add_player(37523, 2358, permutation_t::read("1,3,5,4,2"), 3, 9, 6, false);
    wc.add_player(14797, 70027, permutation_t::read("1,5,4,3,2"), 8, 11, 30, false);
    wc.add_team(76052);
    wc.play_match(78450, 5);
    wc.add_player(6392, 31655, permutation_t::read("1,2,3,4,5"), 15, 4, 16, false);
    wc.add_team(10);
    wc.add_player(69433, 70027, permutation_t::read("4,2,3,1,5"), 19, 11, 21, false);
    wc.add_player(80613, 13714, permutation_t::read("3,4,5,2,1"), 1, 7, 11, false);
    wc.get_team_points(45754);
    wc.add_player(44162, 76052, permutation_t::read("1,2,5,3,4"), 13, 14, 9, false);
    wc.get_partial_spirit(69433);
    wc.add_team(89451);
    wc.add_player(29882, 93992, permutation_t::read("2,5,3,4,1"), 22, 12, 21, false);
    wc.add_player(50682, 4, permutation_t::read("3,5,2,1,4"), 1, 25, 22, true);
    wc.add_player(98664, 17676, permutation_t::read("4,1,5,3,2"), 18, 28, 20, false);
    wc.play_match(93992, 10);
    wc.add_player(79256, 64, permutation_t::read("3,5,1,2,4"), -19, 11, 2, false);
    wc.add_player(20392, 988, permutation_t::read("5,1,4,2,3"), 29, 11, 19, false);
    wc.num_played_games_for_player(51193);
    wc.get_partial_spirit(5608);
    wc.num_played_games_for_player(88417);
    wc.add_team(89532);
    wc.add_player(16, 85232, permutation_t::read("3,2,4,5,1"), 16, 17, 24, false);
    wc.add_team(2);
    wc.get_partial_spirit(20392);
    wc.add_player(48668, 8, permutation_t::read("1,3,5,2,4"), 21, 2, 7, true);
    wc.get_partial_spirit(3921);
    wc.add_player(51963, 58673, permutation_t::read("2,5,3,1,4"), 28, 27, 21, false);
    wc.remove_team(8);
    wc.buy_team(3, 3);
    wc.add_player(91073, 77248, permutation_t::read("5,3,4,1,2"), 11, 12, 21, true);
    wc.get_ith_pointless_ability(31);
    wc.add_player(24313, 5, permutation_t::read("2,1,3,5,4"), 9, 8, 19, false);
    wc.remove_team(41817);
    wc.add_player(33286, 17676, permutation_t::read("3,4,2,5,1"), 25, 13, 13, false);
    wc.get_partial_spirit(8320);
    wc.add_player(42581, 3, permutation_t::read("5,2,4,3,1"), 26, 19, 2, false);
    wc.get_partial_spirit(87836);
    wc.add_player(54677, 44765, permutation_t::read("2,1,3,4,5"), 5, -8, 2, false);
    wc.get_team_points(31655);
    wc.add_team(19733);
    wc.add_player(3360, 89532, permutation_t::read("1,4,2,5,3"), 13, 0, -4, false);
    wc.add_player_cards(23910, 0);
    wc.add_player(43036, 988, permutation_t::read("4,2,5,3,1"), 28, 8, 18, false);
    wc.add_player(48133, 8, permutation_t::read("1,5,3,4,2"), 23, 23, 1, false);
    wc.play_match(2714, 4);
    wc.get_partial_spirit(28842);
    wc.add_player(48514, 48718, permutation_t::read("2,4,3,1,5"), 9, 8, 18, false);
    wc.play_match(988, 10);
    wc.add_player(90665, 988, permutation_t::read("1,2,4,3,5"), 13, 9, 16, false);
    wc.add_player(14770, 91746, permutation_t::read("4,3,2,5,1"), 1, 23, 10, false);
    wc.num_played_games_for_player(92468);
    wc.add_player(83776, 57578, permutation_t::read("5,2,3,1,4"), 5, 28, 0, false);
    wc.add_team(4);
    wc.add_player(13340, 2, permutation_t::read("3,5,2,4,1"), 29, 10, 20, false);
    wc.get_ith_pointless_ability(32);
    wc.add_player(67602, 77248, permutation_t::read("1,3,4,5,2"), 4, 0, 20, false);
    wc.play_match(28668, 70027);
    wc.get_ith_pointless_ability(39);
    wc.get_partial_spirit(29946);
    wc.num_played_games_for_player(50682);
    wc.add_team(24273);
    wc.add_player(15287, 63411, permutation_t::read("3,4,1,5,2"), 11, 20, 18, false);
    wc.add_team(41611);
    wc.add_team(81420);
    wc.add_team(96404);
    wc.get_team_points(65750);
    wc.get_partial_spirit(43922);
    wc.add_team(66);
    wc.play_match(45754, 64);
    wc.add_player(94261, 42255, permutation_t::read("1,4,5,2,3"), 5, 10, 11, false);
    wc.num_played_games_for_player(74182);
    wc.add_player(4095, 14258, permutation_t::read("1,3,4,2,5"), 0, 7, 28, false);
    wc.add_player(29292, 21728, permutation_t::read("1,4,3,2,5"), 22, 29, 13, false);
    wc.add_team(7);
    wc.add_team(7);
    wc.get_team_points(31655);
    wc.num_played_games_for_player(75578);
    wc.add_player(99869, 28668, permutation_t::read("4,5,2,1,3"), 10, 25, 18, false);
    wc.get_partial_spirit(23835);
    wc.get_team_points(63511);
    wc.get_team_points(5434);
    wc.add_player(87044, 63511, permutation_t::read("2,5,4,1,3"), 8, 3, 23, false);
    wc.play_match(97, 36920);
    wc.get_ith_pointless_ability(72);
    wc.add_team(85020);
    wc.add_player(50768, 58673, permutation_t::read("2,5,4,1,3"), 29, 4, 27, false);
    wc.add_player(22420, 23716, permutation_t::read("2,4,3,5,1"), 24, 2, 2, true);
    wc.num_played_games_for_player(91272);
    wc.num_played_games_for_player(94261);
    wc.num_played_games_for_player(18232);
    wc.remove_team(41611);
    wc.add_player(99910, 92973, permutation_t::read("4,3,2,5,1"), 12, 11, 22, true);
    wc.remove_team(7);
    wc.add_player(74363, 1592, permutation_t::read("4,2,3,1,5"), 22, 26, 14, false);
    wc.add_team(50337);
    wc.add_player(45585, 97, permutation_t::read("2,3,5,1,4"), 6, 28, 0, false);
    wc.get_team_points(63511);
    wc.add_team(8);
    wc.add_player(39065, 49, permutation_t::read("5,1,3,4,2"), 7, 12, 17, false);
    wc.remove_team(44765);
    wc.add_team(92256);
    wc.add_player(95495, 19889, permutation_t::read("4,3,5,2,1"), 21, 20, 20, true);
    wc.get_ith_pointless_ability(66);
    wc.add_player(7659, 2714, permutation_t::read("4,1,5,2,3"), 13, 23, 23, false);
    wc.num_played_games_for_player(85343);
    wc.add_team(98702);
    wc.get_ith_pointless_ability(32);
    wc.add_player(5892, 7, permutation_t::read("3,5,2,4,1"), 30, 19, 6, false);
    wc.add_player(88528, 89451, permutation_t::read("1,4,2,5,3"), 29, 17, 18, false);
    wc.add_player_cards(21524, 25);
    wc.add_player_cards(91233, 10);
    wc.get_ith_pointless_ability(41);
    wc.get_team_points(64);
    wc.num_played_games_for_player(95495);
    wc.get_partial_spirit(87815);
    wc.get_ith_pointless_ability(11);
    wc.add_team(88719);
    wc.get_team_points(44765);
    wc.add_player(45329, 89532, permutation_t::read("3,4,5,2,1"), 4, 2, 5, false);
    wc.add_player(98786, 92967, permutation_t::read("5,1,3,2,4"), 22, 16, 30, false);
    wc.add_player(11577, 41611, permutation_t::read("2,3,5,1,4"), 7, 3, 25, false);
    wc.add_player_cards(16639, 15);
    wc.add_player(14204, 988, permutation_t::read("3,2,4,5,1"), 0, 29, 8, false);
    wc.get_team_points(20508);
    wc.get_ith_pointless_ability(61);
    wc.play_match(70027, 10);
    wc.add_team(1450);
    wc.play_match(8, 85020);
    wc.get_ith_pointless_ability(71);
    wc.get_partial_spirit(92468);
    wc.add_player_cards(95738, 6);
    wc.play_match(7, 64);
    wc.add_player(38818, 78270, permutation_t::read("2,4,1,5,3"), 15, 27, 9, false);
    wc.add_team(92990);
    wc.add_player(4154, 48482, permutation_t::read("5,1,4,2,3"), 22, 4, 7, false);
    wc.remove_team(96404);
    wc.get_partial_spirit(21385);
    wc.play_match(98702, 87409);
    wc.add_player(79078, 31655, permutation_t::read("2,1,3,4,5"), 22, 12, 6, false);
    wc.add_player(19697, 3, permutation_t::read("5,1,4,2,3"), 18, 7, 11, false);
    wc.add_player_cards(76813, 4);
    wc.add_player(18200, 64, permutation_t::read("2,4,1,3,5"), 15, 24, 17, false);
    wc.add_team(3);
    wc.play_match(4, 83);
    wc.play_match(94096, 2);
    wc.add_player(20138, 31655, permutation_t::read("5,1,3,2,4"), 18, 14, 3, false);
    wc.add_player(63203, 5, permutation_t::read("3,4,2,1,5"), 5, 0, 28, false);
    wc.num_played_games_for_player(21385);
    wc.get_ith_pointless_ability(2);
    wc.get_ith_pointless_ability(52);
    wc.play_match(65750, 64);
    wc.add_team(4645);
    wc.get_ith_pointless_ability(30);
    wc.add_player(96619, 98129, permutation_t::read("3,1,5,4,2"), 10, 17, 1, false);
    wc.get_ith_pointless_ability(62);
    wc.add_team(32121);
    wc.num_played_games_for_player(53116);
    wc.add_player_cards(23835, 20);
    wc.add_player(64213, 44765, permutation_t::read("4,5,2,3,1"), 7, 10, 21, true);
    wc.add_player(42397, 3, permutation_t::read("1,3,2,4,5"), 8, 25, 10, true);
    wc.add_player(42559, 92973, permutation_t::read("5,3,1,4,2"), 5, 12, 10, true);
    wc.get_partial_spirit(14204);
    wc.add_player(3550, 5434, permutation_t::read("5,1,4,2,3"), 23, 23, 30, false);
    wc.get_partial_spirit(7922);
    wc.add_player(74430, 5, permutation_t::read("2,1,3,4,5"), 9, 27, 19, false);
    wc.add_team(44082);
    wc.add_player(5695, 10, permutation_t::read("1,5,2,4,3"), 30, 4, 7, true);
    wc.buy_team(7, 8);
    wc.add_player(39086, 17676, permutation_t::read("4,5,1,3,2"), 24, 3, 15, false);
    wc.get_team_points(2);
    wc.num_played_games_for_player(43036);
    wc.add_player(8929, 8, permutation_t::read("1,5,2,3,4"), 30, 20, 0, false);
    wc.add_player(-7, 35606, permutation_t::read("1,5,2,3,4"), 0, 15, 17, false);
    wc.add_player(78713, 78270, permutation_t::read("4,2,1,3,5"), 9, 8, 30, false);
    wc.num_played_games_for_player(54297);
    wc.play_match(3, 10);
    wc.add_player(21702, 48718, permutation_t::read("2,4,5,3,1"), 23, 9, 30, false);
    wc.get_ith_pointless_ability(39);
    wc.add_player(74092, 23716, permutation_t::read("4,1,5,3,2"), 13, 19, 23, false);
    wc.play_match(7, 44765);
    wc.get_ith_pointless_ability(73);
    wc.get_team_points(62416);
    wc.get_team_points(87409);
    wc.num_played_games_for_player(86453);
    wc.num_played_games_for_player(5892);
    wc.add_player(3173, 78450, permutation_t::read("2,1,3,5,4"), 19, 7, 8, false);
    wc.num_played_games_for_player(20416);
    wc.add_team(44116);
    wc.num_played_games_for_player(4095);
    wc.add_player_cards(20873, 43);
    wc.add_player(68075, 66, permutation_t::read("3,5,4,2,1"), 16, 25, 29, false);
    wc.buy_team(89451, 21924);
    wc.add_team(10);
    wc.add_player(80901, 7, permutation_t::read("1,2,5,3,4"), 21, 20, 28, false);
    wc.num_played_games_for_player(79256);
    wc.add_player(61260, 48569, permutation_t::read("5,3,2,1,4"), 22, 25, 11, false);
    wc.get_ith_pointless_ability(5);
    wc.get_team_points(63511);
    wc.add_team(30144);
    wc.add_player(6699, 7, permutation_t::read("5,3,4,1,2"), 14, 22, 20, false);
    wc.num_played_games_for_player(79078);
    wc.get_ith_pointless_ability(25);
    wc.get_ith_pointless_ability(72);
    wc.add_player(80444, 89451, permutation_t::read("2,4,3,1,5"), 10, 29, 17, false);
    wc.num_played_games_for_player(69017);
    wc.num_played_games_for_player(34326);
    wc.add_player_cards(40971, 7);
    wc.get_team_points(2358);
    wc.play_match(9, 94096);
    wc.get_team_points(98702);
    wc.play_match(66, 55585);
    wc.add_player(4403, 7, permutation_t::read("1,5,3,4,2"), 9, 4, 4, false);
    wc.add_team(48210);
    wc.add_player(61704, 89451, permutation_t::read("5,1,2,4,3"), 25, 35, 8, false);
    wc.get_team_points(4645);
    wc.num_played_games_for_player(91233);
    wc.num_played_games_for_player(87381);
    wc.add_player(10947, 19889, permutation_t::read("4,3,5,2,1"), 10, 29, 20, false);
    wc.add_team(47067);
    wc.add_player(25788, 92256, permutation_t::read("2,3,1,4,5"), 19, 2, 29, false);
    wc.play_match(4, 46044);
    wc.get_partial_spirit(69445);
    wc.buy_team(94096, 1592);
    wc.add_team(16327);
    wc.add_player(94071, 35606, permutation_t::read("5,3,1,2,4"), 26, 8, 27, false);
    wc.add_player(56895, 92990, permutation_t::read("4,1,3,2,5"), -18, 8, 25, false);
    wc.add_player(47648, 20508, permutation_t::read("2,3,5,4,1"), 0, 23, 30, false);
    wc.add_team(2924);
    wc.add_team(33478);
    wc.get_team_points(10);
    wc.get_partial_spirit(20873);
    wc.add_player_cards(90665, 26);
    wc.num_played_games_for_player(20138);
    wc.play_match(8, 7);
    wc.num_played_games_for_player(10835);
    wc.add_player(33585, 8, permutation_t::read("4,3,1,2,5"), 17, 12, 20, false);
    wc.add_player(92418, 2, permutation_t::read("5,2,1,4,3"), 17, 19, 7, false);
    wc.get_ith_pointless_ability(55);
    wc.add_player(56113, 1450, permutation_t::read("2,1,3,5,4"), 6, 27, 15, false);
    wc.get_team_points(4);
    wc.add_player(45852, 66, permutation_t::read("4,1,3,2,5"), 96, 28, 30, false);
    wc.get_ith_pointless_ability(25);
    wc.add_player(87415, 41817, permutation_t::read("1,4,3,2,5"), 2, 24, 1, false);
    wc.add_player(82140, 77248, permutation_t::read("1,4,5,3,2"), 14, 6, 21, false);
    wc.add_team(61734);
    wc.get_partial_spirit(24313);
    wc.add_player(89877, 34070, permutation_t::read("5,2,4,3,1"), 21, 25, 17, false);
    wc.get_partial_spirit(95738);
    wc.play_match(5, 7);
    wc.add_team(61535);
    wc.add_team(86494);
    wc.add_player_cards(23835, 21);
    wc.add_player(66038, 4, permutation_t::read("5,2,4,3,1"), 26, 22, 19, false);
    wc.add_player(78132, 85020, permutation_t::read("3,4,5,2,1"), 16, 27, 19, false);
    wc.add_player(15514, 47067, permutation_t::read("2,4,1,5,3"), 22, 27, 26, false);
    wc.add_player(39344, 98129, permutation_t::read("3,4,2,5,1"), 2, 20, 1, false);
    wc.get_team_points(47067);
    wc.add_player(15063, 31655, permutation_t::read("4,5,2,3,1"), 27, 17, 0, false);
    wc.add_team(23009);
    wc.add_player(92215, 58527, permutation_t::read("3,1,5,2,4"), 5, 6, 54, false);
    wc.add_player(9870, 93992, permutation_t::read("1,3,2,5,4"), 24, 25, 30, false);
    wc.add_team(52844);
    wc.add_player_cards(55682, 22);
    wc.add_player(42944, 30936, permutation_t::read("4,2,3,1,5"), 28, 21, 10, false);
    wc.add_player(22126, 41611, permutation_t::read("2,1,3,4,5"), 20, 30, 29, false);
    wc.add_team(92462);
    wc.add_player(5979, 98255, permutation_t::read("4,2,3,1,5"), 21, 10, 17, false);
    wc.add_player_cards(48668, 21);
    wc.get_team_points(88719);
    wc.get_team_points(91746);
    wc.add_player(3691, 19733, permutation_t::read("1,2,3,5,4"), 22, 1, 27, false);
    wc.add_player(61179, 20508, permutation_t::read("2,4,1,5,3"), 17, 18, 22, false);
    wc.add_player(22792, 88719, permutation_t::read("1,4,3,2,5"), 17, 25, 17, false);
    wc.play_match(78270, 23009);
    wc.play_match(23009, 13714);
    wc.add_player(57127, 20508, permutation_t::read("3,1,5,4,2"), 16, -19, 28, false);
    wc.play_match(64, 48569);
    wc.add_player(37915, 41817, permutation_t::read("4,3,1,2,5"), 15, 10, 16, false);
    wc.remove_team(65750);
    wc.add_player(86403, 70027, permutation_t::read("4,1,5,2,3"), 17, 24, 6, false);
    wc.num_played_games_for_player(23807);
    wc.add_player(561, 83, permutation_t::read("3,4,5,2,1"), 22, 0, 3, false);
    wc.add_player(69, 97, permutation_t::read("2,5,1,4,3"), 29, 7, 2, false);
    wc.add_player(75333, 36920, permutation_t::read("3,1,5,2,4"), 12, 19, 27, false);
    wc.buy_team(92256, 44765);
    wc.remove_team(61734);
    wc.add_team(25729);
    wc.add_player(49605, 4, permutation_t::read("4,2,3,5,1"), 30, 6, 15, true);
    wc.add_player(17066, 30144, permutation_t::read("4,1,2,3,5"), 24, 8, 4, false);
    wc.add_player(63187, 71245, permutation_t::read("4,3,5,2,1"), 21, 30, 24, false);
    wc.play_match(21728, 19733);
    wc.add_player(14834, 97, permutation_t::read("4,5,2,3,1"), 6, 9, 9, false);
    wc.get_partial_spirit(95291);
    wc.get_partial_spirit(99910);
    wc.add_player_cards(80901, 6);
    wc.add_player(1519, 44116, permutation_t::read("4,1,5,3,2"), 9, 26, 29, false);
    wc.get_partial_spirit(52159);
    wc.add_player(44267, 28668, permutation_t::read("3,4,5,1,2"), 17, 3, 17, false);
    wc.buy_team(4, 59352);
    wc.remove_team(42255);
    wc.add_player(4441, 64, permutation_t::read("2,1,3,4,5"), 4, 13, 3, false);
    wc.get_ith_pointless_ability(12);
    wc.add_team(47407);
    wc.add_player(77773, 36920, permutation_t::read("1,3,5,4,2"), 20, 16, 12, false);
    wc.add_player(88000, 89451, permutation_t::read("5,2,4,3,1"), 2, 22, 3, false);
    wc.add_player(69455, 52024, permutation_t::read("1,2,3,4,5"), 27, 11, 11, false);
    wc.add_team(62125);
    wc.add_player(57742, 58673, permutation_t::read("4,5,3,2,1"), 3, 24, 8, false);
    wc.get_team_points(48210);
    wc.add_player(66664, 23009, permutation_t::read("3,2,4,1,5"), 11, 20, 11, false);
    wc.num_played_games_for_player(29946);
    wc.add_player(47891, 88719, permutation_t::read("3,4,5,1,2"), 6, 24, 9, false);
    wc.add_player_cards(77900, 13);
    wc.get_team_points(70027);
    wc.add_player(49347, 10, permutation_t::read("3,5,4,2,1"), 19, 19, 9, false);
    wc.get_partial_spirit(5979);
    wc.get_ith_pointless_ability(5);
    wc.add_team(6321);
    wc.add_player(32597, 10, permutation_t::read("5,4,3,2,1"), 11, 29, 5, false);
    wc.add_player(65958, 2714, permutation_t::read("3,5,2,4,1"), 10, 20, 29, true);
    wc.add_player(44344, 1450, permutation_t::read("2,5,4,3,1"), 14, 28, 1, false);
    wc.add_player_cards(90498, 11);
    wc.buy_team(4, 66);
    wc.add_team(58824);
    wc.play_match(78270, 28668);
    wc.play_match(5, 44765);
    wc.add_player(36175, 1450, permutation_t::read("4,5,3,2,1"), 26, 9, 5, false);
    wc.add_player(66699, 14258, permutation_t::read("5,2,4,1,3"), 25, 7, 11, false);
    wc.play_match(86494, 23716);
    wc.add_player(40247, 4, permutation_t::read("4,3,5,1,2"), 16, 23, 2, true);
    wc.add_player(43361, 2714, permutation_t::read("3,1,2,4,5"), 11, 7, 11, false);
    wc.add_player(48912, 4, permutation_t::read("2,4,3,1,5"), 19, 18, 6, false);
    wc.add_player(51575, 71245, permutation_t::read("2,3,4,1,5"), 26, 20, 1, false);
    wc.play_match(76052, 46044);
    wc.add_player_cards(76560, 6);
    wc.add_player(8984, 31655, permutation_t::read("1,2,4,5,3"), 0, 7, 2, false);
    wc.buy_team(10, 8);
    wc.get_partial_spirit(36175);
    wc.add_team(3);
    wc.get_team_points(87409);
    wc.get_team_points(25729);
    wc.add_team(86744);
    wc.add_team(91378);
    wc.add_team(36665);
    wc.get_team_points(48718);
    wc.get_ith_pointless_ability(57);
    wc.num_played_games_for_player(78463);
    wc.play_match(16327, 6321);
    wc.add_player_cards(66664, 23);
    wc.add_player(34123, 41611, permutation_t::read("3,4,5,1,2"), 21, 12, 5, false);
    wc.play_match(6321, 14258);
    wc.num_played_games_for_player(8984);
    wc.add_team(1);
    wc.get_ith_pointless_ability(50);
    wc.buy_team(64, 66);
    wc.play_match(36665, 21924);
    wc.remove_team(3);
    wc.add_player(7866, 8, permutation_t::read("5,3,2,4,1"), 8, 0, 11, false);
    wc.add_player(65813, 44082, permutation_t::read("1,5,2,3,4"), 18, 2, 27, false);
    wc.remove_team(91746);
    wc.buy_team(31655, 64);
    wc.add_team(3);
    wc.add_player(71509, 85020, permutation_t::read("3,4,5,1,2"), 19, 9, 20, false);
    wc.add_team(748);
    wc.play_match(8, 2);
    wc.add_player(4011, 91746, permutation_t::read("3,5,2,4,1"), 30, 28, 4, false);
    wc.num_played_games_for_player(25133);
    wc.buy_team(47407, 2);
    wc.add_player(35506, 4, permutation_t::read("3,4,5,1,2"), 12, 14, 12, true);
    wc.add_player(69503, 5434, permutation_t::read("4,5,2,3,1"), 73, 7, 27, false);
    wc.add_player(13569, 85232, permutation_t::read("1,2,5,3,4"), 11, 25, 10, false);
    wc.get_partial_spirit(42581);
    wc.add_player(52214, 13714, permutation_t::read("5,2,4,3,1"), 9, 12, 5, false);
    wc.get_team_points(80304);
    wc.add_player(9578, 45754, permutation_t::read("2,4,1,5,3"), 1, 9, 28, false);
    wc.play_match(1, 4);
    wc.get_ith_pointless_ability(79);
    wc.add_player(74874, 23716, permutation_t::read("4,1,2,5,3"), 28, 0, 19, false);
    wc.add_player(85858, 97, permutation_t::read("3,2,4,5,1"), 4, 28, 7, false);
    wc.add_player(91763, 37986, permutation_t::read("3,2,1,4,5"), 9, 25, 19, false);
    wc.get_ith_pointless_ability(29);
    wc.add_player(16102, 2, permutation_t::read("2,4,3,5,1"), 28, 25, 28, false);
    wc.add_player(90701, 78270, permutation_t::read("2,4,5,1,3"), 1, 7, 17, false);
    wc.buy_team(89451, 70027);
    wc.add_player(6925, 92967, permutation_t::read("1,3,5,2,4"), 24, 8, 21, true);
    wc.add_team(57820);
    wc.add_player(70362, 30936, permutation_t::read("1,5,2,3,4"), 3, 12, 4, true);
    wc.add_player(70919, 4645, permutation_t::read("3,5,1,2,4"), 20, 2, 19, false);
    wc.add_player_cards(67602, 16);
    wc.remove_team(5);
    wc.get_partial_spirit(10947);
    wc.play_match(94096, 44082);
    wc.add_player(63840, 92990, permutation_t::read("2,4,3,5,1"), 11, 27, 20, false);
    wc.add_player(91544, 48569, permutation_t::read("2,4,1,5,3"), 28, 29, 10, false);
    wc.add_player(86542, 48718, permutation_t::read("2,1,4,3,5"), 28, 16, 19, false);
    wc.get_team_points(98129);
    wc.num_played_games_for_player(95424);
    wc.get_partial_spirit(5351);
    wc.add_player(90879, 62416, permutation_t::read("5,2,3,1,4"), 24, 15, 29, false);
    wc.add_team(80880);
    wc.play_match(77248, 50337);
    wc.get_ith_pointless_ability(3);
    wc.add_player(74194, 57578, permutation_t::read("4,3,5,1,2"), 11, 1, 29, false);
    wc.play_match(1450, 2358);
    wc.add_player_cards(48912, 27);
    wc.add_player(27083, 58824, permutation_t::read("2,1,5,4,3"), 15, 12, 5, false);
    wc.add_player(45310, 1592, permutation_t::read("5,4,2,3,1"), 25, 9, 6, false);
    wc.add_player(17897, 30936, permutation_t::read("3,1,4,5,2"), 28, 7, 19, false);
    wc.play_match(5, 88719);
    wc.add_player(9653, 30144, permutation_t::read("1,4,2,3,5"), 10, 1, 0, false);
    wc.add_team(33973);
    wc.num_played_games_for_player(5892);
    wc.num_played_games_for_player(63203);
    wc.num_played_games_for_player(49347);
    wc.add_team(82442);
    wc.get_ith_pointless_ability(64);
    wc.get_ith_pointless_ability(11);
    wc.num_played_games_for_player(16476);
    wc.num_played_games_for_player(95495);
    wc.get_team_points(1);
    wc.add_player(77857, 57357, permutation_t::read("5,1,2,4,3"), 29, 16, 4, false);
    wc.get_ith_pointless_ability(44);
    wc.add_player_cards(3550, 25);
    wc.add_player(92496, 5434, permutation_t::read("4,5,2,3,1"), 14, 11, 2, false);
    wc.add_player(16464, 85232, permutation_t::read("5,2,3,1,4"), 16, 5, 19, false);
    wc.get_partial_spirit(5948);
    wc.add_player(88592, 48569, permutation_t::read("5,3,4,1,2"), 1, 29, 24, false);
    wc.add_player_cards(55682, 29);
    wc.add_player(87557, 61734, permutation_t::read("5,1,4,3,2"), 15, 3, 14, false);
    wc.add_player(4442, 21924, permutation_t::read("2,1,4,5,3"), 15, 16, 11, false);
    wc.add_team(37544);
    wc.add_team(24858);
    wc.get_team_points(57578);
    wc.play_match(1, 50337);
    wc.get_partial_spirit(23807);
    wc.add_team(63196);
    wc.add_player(67117, 89451, permutation_t::read("3,5,1,2,4"), 26, 20, 6, false);
    wc.add_player(87237, 85020, permutation_t::read("1,5,3,2,4"), 30, 8, 13, true);
    wc.play_match(1592, 48569);
    wc.get_partial_spirit(11941);
    wc.add_player_cards(14373, 26);
    wc.num_played_games_for_player(87836);
    wc.add_team(3584);
    wc.add_player(28264, 748, permutation_t::read("2,3,4,1,5"), 18, 1, 8, false);
    wc.add_team(42594);
    wc.add_player(1899, 23716, permutation_t::read("3,2,5,1,4"), 16, 16, 19, false);
    wc.add_player(48788, 63511, permutation_t::read("1,3,4,2,5"), 15, 8, 8, true);
    wc.add_player(32508, 30144, permutation_t::read("4,5,2,3,1"), 19, 4, 2, false);
    wc.play_match(988, 50337);
    wc.add_team(29);
    wc.play_match(29, 21728);
    wc.add_player(82487, 2, permutation_t::read("3,5,2,1,4"), 0, 1, 15, false);
    wc.add_player(85287, 80304, permutation_t::read("4,1,5,3,2"), 27, 22, 7, false);
    wc.buy_team(71245, 85020);
    wc.add_player(36292, 2, permutation_t::read("4,1,2,5,3"), 11, 9, 19, false);
    wc.get_partial_spirit(72659);
    wc.num_played_games_for_player(34429);
    wc.add_player(75321, 2, permutation_t::read("4,1,2,3,5"), 18, 30, 11, false);
    wc.get_team_points(8);
    wc.get_team_points(4);
    wc.add_player(87932, 37544, permutation_t::read("1,5,4,2,3"), 29, 10, 20, true);
    wc.num_played_games_for_player(75578);
    wc.get_partial_spirit(57127);
    wc.play_match(8, 91746);
    wc.add_player(85814, 2714, permutation_t::read("5,4,3,1,2"), 20, 18, 16, false);
    wc.add_team(32882);
    wc.buy_team(-12, 2);
    wc.add_player(6418, 63196, permutation_t::read("2,3,4,5,1"), 11, 30, 1, false);
    wc.add_player(74719, 24858, permutation_t::read("5,1,3,2,4"), 24, 16, 30, false);
    wc.add_team(1036);
    wc.num_played_games_for_player(58179);
    wc.num_played_games_for_player(4274);
    wc.remove_team(97384);
    wc.get_team_points(36665);
    wc.remove_team(30144);
    wc.get_team_points(29);
    wc.num_played_games_for_player(32158);
    wc.get_ith_pointless_ability(78);
    wc.add_player(-16, 7, permutation_t::read("3,4,5,1,2"), 14, 26, 25, false);
    wc.add_player(54126, 1036, permutation_t::read("3,2,5,4,1"), 27, 24, 7, false);
    wc.add_player(33829, 3, permutation_t::read("3,4,2,1,5"), 21, 11, 30, false);
    wc.get_ith_pointless_ability(110);
    wc.add_player(-18, 32121, permutation_t::read("1,2,3,4,5"), 3, 22, 8, false);
    wc.get_partial_spirit(45329);
    wc.add_team(69911);
    wc.add_team(99939);
    wc.add_player(6404, 63411, permutation_t::read("3,5,2,4,1"), 5, 4, 27, false);
    wc.buy_team(69911, 59352);
    wc.add_player(95564, 45754, permutation_t::read("3,1,5,4,2"), 27, 19, 12, false);
    wc.add_player(4286, 58527, permutation_t::read("5,3,1,2,4"), 20, 23, 23, true);
    wc.remove_team(66);
    wc.add_team(5);
    wc.add_player(35697, 42594, permutation_t::read("1,5,4,3,2"), 0, 25, 21, true);
    wc.get_partial_spirit(30749);
    wc.add_player(87630, 80304, permutation_t::read("4,1,5,2,3"), 24, 26, 1, false);
    wc.add_player(65852, 42594, permutation_t::read("1,2,3,4,5"), 23, 30, 3, false);
    wc.get_ith_pointless_ability(74);
    wc.get_team_points(92256);
    wc.add_player(47776, 98255, permutation_t::read("2,5,3,4,1"), 19, 29, 15, false);
    wc.play_match(4645, 23009);
    wc.add_team(66740);
    wc.get_ith_pointless_ability(90);
    wc.add_player(51847, 35606, permutation_t::read("3,4,2,5,1"), 10, 5, 16, false);
    wc.add_player(9638, 37986, permutation_t::read("3,4,2,1,5"), 54, 5, 0, true);
    wc.buy_team(23716, 23009);
    wc.add_player(59896, 93992, permutation_t::read("3,4,5,1,2"), 16, 19, 22, false);
    wc.get_team_points(29);
    wc.num_played_games_for_player(44162);
    wc.play_match(42594, 58527);
    wc.add_player(7176, 99939, permutation_t::read("4,3,5,1,2"), 4, 19, 16, true);
    wc.add_player(85073, 19733, permutation_t::read("2,4,1,5,3"), 23, 15, 12, false);
    wc.buy_team(92967, 10);
    wc.add_player_cards(2393, 3);
    wc.add_player(97071, 8, permutation_t::read("2,3,1,5,4"), 25, 23, 14, false);
    wc.add_team(25607);
    wc.add_player(64080, 62, permutation_t::read("2,5,3,1,4"), 16, 19, 22, false);
    wc.get_ith_pointless_ability(12);
    wc.add_player_cards(32089, 28);
    wc.add_team(6);
    wc.get_partial_spirit(69455);
    wc.add_player(39874, 98255, permutation_t::read("1,5,4,2,3"), 28, 9, 29, true);
    wc.get_partial_spirit(44162);
    wc.play_match(4, 17676);
    wc.add_team(30817);
    wc.add_player(75485, 1, permutation_t::read("3,5,1,4,2"), 3, 11, 22, false);
    wc.add_player(97160, 21924, permutation_t::read("1,4,3,2,5"), 14, 15, 7, false);
    wc.get_partial_spirit(27083);

    return 0;
}