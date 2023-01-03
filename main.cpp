
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
    wc.add_team(56198);
    wc.add_team(6);
    wc.play_match(56198, 56198);
    wc.num_played_games_for_player(37692);
    wc.get_ith_pointless_ability(1);
    wc.add_team(15362);
    wc.get_partial_spirit(1531);
    wc.add_team(74209);
    wc.add_team(19511);
    wc.get_partial_spirit(23499);
    wc.add_player(97385, 56198, permutation_t::read("1,4,5,2,3"), 4, 2, 22, true);
    wc.add_player(62910, 19511, permutation_t::read("4,2,3,1,5"), 24, 27, 22, false);
    wc.add_player(61672, 74209, permutation_t::read("4,5,1,3,2"), 27, 16, 12, false);
    wc.play_match(15362, 56198);
    wc.get_ith_pointless_ability(1);
    wc.get_partial_spirit(97385);
    wc.add_team(10168);
    wc.add_player(12306, 74209, permutation_t::read("3,5,1,2,4"), 21, 1, 21, true);
    wc.add_team(79671);
    wc.get_ith_pointless_ability(6);
    wc.add_player(94190, 79671, permutation_t::read("5,4,2,1,3"), 10, 12, 8, false);
    wc.play_match(10168, 10168);
    wc.num_played_games_for_player(94190);
    wc.play_match(56198, 79671);
    wc.add_team(7452);
    wc.buy_team(56198, 6);
    wc.remove_team(7452);
    wc.add_player(98155, 6, permutation_t::read("2,1,5,3,4"), 22, 29, 28, true);
    wc.num_played_games_for_player(12306);
    wc.add_player(62384, 19511, permutation_t::read("1,3,5,4,2"), 24, 16, 17, false);
    wc.add_player_cards(62910, 14);
    wc.add_player_cards(62384, 29);
    wc.add_player(83903, 15362, permutation_t::read("4,3,5,2,1"), 12, 13, 9, false);
    wc.play_match(56198, 74209);
    wc.num_played_games_for_player(97385);
    wc.get_ith_pointless_ability(5);
    wc.add_player(21538, 15362, permutation_t::read("1,5,4,3,2"), 10, -2, 14, true);
    wc.add_player(27206, 10168, permutation_t::read("3,2,5,1,4"), 6, 5, 22, false);
    wc.add_player(80701, 7452, permutation_t::read("3,2,5,4,1"), 0, 9, 42, false);
    wc.add_player(25109, 7452, permutation_t::read("2,3,5,1,4"), 2, 19, 23, false);
    wc.add_player(56, 56198, permutation_t::read("4,1,3,5,2"), 18, 8, 22, false);
    wc.add_player(78, 10168, permutation_t::read("2,1,4,3,5"), 13, 11, 24, false);
    wc.get_ith_pointless_ability(4);
    wc.add_player(65716, 7452, permutation_t::read("3,2,5,1,4"), 16, 6, 11, false);
    wc.add_team(7198);
    wc.add_player(5230, 7452, permutation_t::read("5,4,3,1,2"), 0, 27, 13, true);
    wc.get_partial_spirit(12306);
    wc.add_team(20512);
    wc.add_player(3882, 10168, permutation_t::read("4,3,1,5,2"), 26, 15, 16, true);
    wc.add_team(60123);
    wc.get_team_points(74209);
    wc.num_played_games_for_player(94190);
    wc.add_player(77882, 20512, permutation_t::read("4,1,2,3,5"), 15, 83, 19, true);
    wc.get_ith_pointless_ability(7);
    wc.add_team(85448);
    wc.get_partial_spirit(62384);
    wc.get_ith_pointless_ability(3);
    wc.add_player(92072, 7452, permutation_t::read("3,2,1,4,5"), 21, 22, 30, false);
    wc.add_player(23, 74209, permutation_t::read("4,3,5,1,2"), 16, 18, 22, true);
    wc.add_player(63810, 49, permutation_t::read("2,5,1,3,4"), 8, 5, 28, false);
    wc.buy_team(7198, 56198);
    wc.add_player(58463, 10168, permutation_t::read("3,1,2,5,4"), 10, 22, 28, true);
    wc.add_team(95814);
    wc.add_player(61022, 7452, permutation_t::read("2,3,4,5,1"), 30, 6, 13, false);
    wc.add_player(48519, 56198, permutation_t::read("4,5,3,2,1"), 2, 30, 25, true);
    wc.get_partial_spirit(23);
    wc.num_played_games_for_player(3882);
    wc.play_match(10168, 32);
    wc.add_player(85635, 19511, permutation_t::read("5,1,3,4,2"), 2, 16, 30, true);
    wc.get_partial_spirit(62384);
    wc.add_team(9);
    wc.add_player(27017, 20512, permutation_t::read("1,4,2,3,5"), 13, 28, 13, false);
    wc.add_player(82013, 6, permutation_t::read("2,1,5,3,4"), 17, 19, 22, false);
    wc.num_played_games_for_player(77882);
    wc.get_team_points(60123);
    wc.get_team_points(7198);
    wc.add_player(52886, 56198, permutation_t::read("3,1,4,5,2"), 11, 2, 18, false);
    wc.add_team(23610);
    wc.get_team_points(7198);
    wc.play_match(60123, 56198);
    wc.add_player(19535, 6, permutation_t::read("1,2,4,3,5"), 11, 21, 0, false);
    wc.add_player(85722, 20512, permutation_t::read("1,5,4,3,2"), 9, 13, 20, true);
    wc.get_team_points(15362);
    wc.add_player(89666, 7452, permutation_t::read("3,4,1,2,5"), 0, 19, 28, true);
    wc.add_player(420, 20512, permutation_t::read("5,4,1,3,2"), 14, 13, 22, false);
    wc.num_played_games_for_player(85635);
    wc.play_match(6, 23610);
    wc.add_team(22468);
    wc.add_player(75990, 85448, permutation_t::read("1,3,4,5,2"), 28, 20, 2, false);
    wc.num_played_games_for_player(82013);
    wc.add_player(98025, 56198, permutation_t::read("3,1,5,4,2"), 10, 25, 11, false);
    wc.add_player(34028, 6, permutation_t::read("2,3,5,1,4"), 17, 28, 27, false);
    wc.add_team(15608);
    wc.add_team(30059);
    wc.add_player(3520, 15608, permutation_t::read("3,4,1,5,2"), 19, 6, 7, false);
    wc.add_player(50452, 6, permutation_t::read("5,4,1,3,2"), 5, 19, 26, false);
    wc.num_played_games_for_player(58463);
    wc.num_played_games_for_player(62384);
    wc.num_played_games_for_player(11);
    wc.add_player(64501, 23610, permutation_t::read("4,3,1,2,5"), 24, 27, 29, false);
    wc.play_match(85448, 7198);
    wc.get_team_points(9);
    wc.num_played_games_for_player(52886);
    wc.add_player(45019, 19511, permutation_t::read("1,3,2,5,4"), 4, 8, 19, false);
    wc.add_team(46721);
    wc.get_partial_spirit(89666);
    wc.play_match(7198, 9);
    wc.add_team(6);
    wc.add_player_cards(89666, 8);
    wc.add_player(54660, 95814, permutation_t::read("4,2,1,5,3"), 3, 12, 34, false);
    wc.add_team(12763);
    wc.get_partial_spirit(83903);
    wc.add_player(2661, 46721, permutation_t::read("3,2,1,5,4"), 26, 24, 3, false);
    wc.add_player(29687, 15362, permutation_t::read("5,2,1,4,3"), 17, 30, 10, true);
    wc.add_player(70038, 95814, permutation_t::read("5,1,2,3,4"), 20, 10, 2, false);
    wc.add_player(70829, 23610, permutation_t::read("3,1,5,4,2"), 8, 20, 13, false);
    wc.get_team_points(10168);
    wc.play_match(15362, 85448);
    wc.buy_team(6, 20512);
    wc.add_player(74344, 19511, permutation_t::read("4,3,5,1,2"), 28, 20, 15, false);
    wc.add_player(26750, 79671, permutation_t::read("5,2,1,3,4"), 28, 23, 13, false);
    wc.add_player(86029, 12763, permutation_t::read("4,3,1,5,2"), 21, 30, 5, false);
    wc.add_player(78607, 20512, permutation_t::read("1,5,3,2,4"), 3, 20, 27, false);
    wc.play_match(6, 9);
    wc.add_team(39413);
    wc.get_ith_pointless_ability(18);
    wc.add_player(92457, 39413, permutation_t::read("1,2,5,4,3"), 0, 22, 17, false);
    wc.num_played_games_for_player(3520);
    wc.add_player(94796, 30059, permutation_t::read("1,2,5,3,4"), 16, 4, 30, false);
    wc.get_partial_spirit(85635);
    wc.get_ith_pointless_ability(2);
    wc.remove_team(9);
    wc.add_player(33701, 23610, permutation_t::read("4,2,1,3,5"), 22, 22, 8, false);
    wc.add_team(65910);
    wc.num_played_games_for_player(75990);
    wc.add_team(1);
    wc.buy_team(60123, 95814);
    wc.get_ith_pointless_ability(22);
    wc.get_partial_spirit(83903);
    wc.add_player(70431, 20512, permutation_t::read("2,1,3,4,5"), 11, 25, 7, false);
    wc.add_player(24989, 7198, permutation_t::read("1,5,3,4,2"), 9, 21, 6, false);
    wc.add_player(80260, 6, permutation_t::read("4,3,2,1,5"), 22, 11, 29, true);
    wc.get_partial_spirit(86029);
    wc.play_match(15608, 7452);
    wc.get_team_points(30059);
    wc.get_ith_pointless_ability(11);
    wc.num_played_games_for_player(98025);
    wc.get_team_points(7452);
    wc.get_partial_spirit(74344);
    wc.add_team(95394);
    wc.get_partial_spirit(83903);
    wc.add_player(39730, 7198, permutation_t::read("4,3,2,5,1"), 72, 0, 29, false);
    wc.add_player(52183, 95394, permutation_t::read("1,5,2,3,4"), 4, 26, 3, false);
    wc.add_player(47552, 23610, permutation_t::read("5,1,2,4,3"), 5, 28, 10, false);
    wc.play_match(22468, 95394);
    wc.add_team(4);
    wc.get_ith_pointless_ability(5);
    wc.play_match(10168, 95814);
    wc.add_player(73829, 23610, permutation_t::read("5,2,1,4,3"), 18, 10, 4, true);
    wc.add_player(13503, 23610, permutation_t::read("5,2,1,4,3"), 10, 65, 7, false);
    wc.add_player_cards(78607, 18);
    wc.get_partial_spirit(78607);
    wc.num_played_games_for_player(58463);
    wc.add_player(43892, 42, permutation_t::read("3,2,5,1,4"), 3, 12, 0, false);
    wc.play_match(95814, 15362);
    wc.add_team(7);
    wc.get_team_points(56198);
    wc.add_player_cards(3882, 3);
    wc.add_player(71907, 95814, permutation_t::read("5,3,1,2,4"), 17, 18, 18, false);
    wc.num_played_games_for_player(82013);
    wc.play_match(7198, 7198);
    wc.add_player(39392, 7, permutation_t::read("5,4,1,3,2"), 1, 13, 13, false);
    wc.add_team(3);
    wc.add_team(2);
    wc.add_player(10166, 46721, permutation_t::read("1,3,4,2,5"), 5, 13, 17, false);
    wc.remove_team(15362);
    wc.play_match(7452, 79671);
    wc.num_played_games_for_player(83903);
    wc.add_player(50646, 15362, permutation_t::read("4,3,5,1,2"), 10, 9, 29, true);
    wc.get_ith_pointless_ability(11);
    wc.add_player(61589, 20512, permutation_t::read("5,3,4,2,1"), 29, 7, 2, false);
    wc.add_player(34414, 9, permutation_t::read("4,5,3,1,2"), 7, 13, 7, false);
    wc.add_player(69478, 95394, permutation_t::read("5,2,4,3,1"), 15, 29, 10, false);
    wc.add_team(10);
    wc.add_player(7256, 1, permutation_t::read("4,2,1,3,5"), 30, 14, 5, false);
    wc.add_player(28278, 19511, permutation_t::read("3,2,1,4,5"), 15, 13, 1, false);
    wc.add_player(89357, 4, permutation_t::read("3,4,5,1,2"), 9, 14, 13, false);
    wc.add_team(29272);
    wc.add_player(54110, 95394, permutation_t::read("3,2,4,5,1"), 18, 29, 5, false);
    wc.add_team(43167);
    wc.get_ith_pointless_ability(3);
    wc.add_player(17952, 15608, permutation_t::read("1,4,2,3,5"), 11, 16, 24, false);
    wc.get_team_points(46721);
    wc.remove_team(6);
    wc.add_player(92049, 2, permutation_t::read("2,5,3,1,4"), 26, 3, 6, false);
    wc.get_ith_pointless_ability(5);
    wc.remove_team(74209);
    wc.add_player_cards(98155, 2);
    wc.add_team(8);
    wc.play_match(9, 100);
    wc.get_team_points(4);
    wc.get_team_points(2);
    wc.add_team(51469);
    wc.add_team(7);
    wc.get_partial_spirit(24989);
    wc.get_ith_pointless_ability(32);
    wc.add_player(96490, 2, permutation_t::read("3,5,2,4,1"), 2, 8, 15, false);
    wc.add_player(93105, 1, permutation_t::read("4,2,3,1,5"), 13, 13, 1, false);
    wc.add_player(30918, 7, permutation_t::read("4,3,2,5,1"), 18, 13, 22, false);
    wc.add_team(64814);
    wc.add_team(57);
    wc.add_team(70071);
    wc.add_player(87084, 9, permutation_t::read("3,5,2,4,1"), 25, 23, 15, false);
    wc.add_player(34457, 39413, permutation_t::read("2,5,3,1,4"), 15, 24, 18, false);
    wc.add_player_cards(77882, 23);
    wc.get_partial_spirit(80701);
    wc.add_player(41086, 60123, permutation_t::read("3,2,4,5,1"), 20, 0, 27, false);
    wc.num_played_games_for_player(27017);
    wc.add_player(55756, 7452, permutation_t::read("1,2,3,5,4"), 27, 23, 14, false);
    wc.add_player(31251, -12, permutation_t::read("3,1,5,4,2"), 27, 14, 5, false);
    wc.add_team(69236);
    wc.add_player(67071, 8, permutation_t::read("3,4,1,2,5"), 15, 17, 18, false);
    wc.get_partial_spirit(61589);
    wc.play_match(4, 22468);
    wc.add_player(22700, 8, permutation_t::read("4,5,1,3,2"), 23, 28, 1, false);
    wc.add_player(26702, 8, permutation_t::read("1,4,2,3,5"), 6, 21, 15, false);
    wc.remove_team(4);
    wc.add_player(7698, 4, permutation_t::read("1,4,5,3,2"), 22, 17, 12, false);
    wc.add_player(27770, 6, permutation_t::read("5,3,2,4,1"), 15, 11, 10, false);
    wc.add_player(67394, 46721, permutation_t::read("2,1,4,5,3"), 20, 17, 10, false);
    wc.get_ith_pointless_ability(15);
    wc.add_player(3048, 2, permutation_t::read("1,5,2,4,3"), 0, 30, 25, false);
    wc.get_team_points(20512);
    wc.add_team(25136);
    wc.play_match(95394, 9);
    wc.add_team(41568);
    wc.add_player(3062, 70071, permutation_t::read("2,5,3,4,1"), 27, 30, 18, false);
    wc.get_partial_spirit(30918);
    wc.add_team(6);
    wc.add_player(11166, 10, permutation_t::read("4,5,3,1,2"), 28, 4, 8, true);
    wc.remove_team(9);
    wc.add_team(2);
    wc.num_played_games_for_player(89666);
    wc.get_team_points(22468);
    wc.num_played_games_for_player(80260);
    wc.add_player(92376, 29272, permutation_t::read("4,1,3,5,2"), 10, 10, 7, false);
    wc.add_player(70107, 57, permutation_t::read("5,1,3,4,2"), 19, 15, 17, false);
    wc.get_team_points(69236);
    wc.get_ith_pointless_ability(7);
    wc.add_player(5791, 10, permutation_t::read("3,2,4,1,5"), 1, 3, 27, false);
    wc.add_player(30537, 60123, permutation_t::read("4,3,1,5,2"), 28, 24, 24, false);

    return 0;
}