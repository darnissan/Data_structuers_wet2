
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
    wc.add_team(88);
    wc.add_team(5);
    wc.add_team(87438);
    wc.add_player(7273, 87438, permutation_t::read("2,3,5,4,1"), 20, 9, 27, false);
    wc.get_partial_spirit(7273);
    wc.get_ith_pointless_ability(2);
    wc.add_player(80343, 87438, permutation_t::read("5,3,1,2,4"), 21, 3, 11, true);
    wc.buy_team(88, 5);
    wc.add_team(22669);
    wc.add_player(7929, 22669, permutation_t::read("1,4,5,3,2"), 26, 3, 25, true);
    wc.play_match(22669, 22669);
    wc.add_player_cards(7929, 2);
    wc.get_team_points(5);
    wc.add_player(5151, 87438, permutation_t::read("4,3,2,1,5"), 11, 10, 20, false);
    wc.get_ith_pointless_ability(1);
    wc.play_match(5, 51);
    wc.add_player(64415, 88, permutation_t::read("3,5,2,4,1"), 7, 11, 28, false);
    wc.num_played_games_for_player(7929);
    wc.get_partial_spirit(5151);
    wc.add_player(96839, 5, permutation_t::read("3,1,4,5,2"), 23, 27, 20, true);
    wc.add_player(20093, 87438, permutation_t::read("1,5,3,4,2"), 25, 20, 18, false);
    wc.add_team(17555);
    wc.get_partial_spirit(20093);
    wc.add_player(37026, 5, permutation_t::read("3,1,5,2,4"), 10, 29, 8, false);
    wc.add_team(76860);
    wc.get_team_points(22669);
    wc.add_player_cards(64415, 15);
    wc.get_partial_spirit(80343);
    wc.get_ith_pointless_ability(2);
    wc.num_played_games_for_player(7273);
    wc.add_team(797);
    wc.play_match(5, 76860);
    wc.get_team_points(22669);
    wc.buy_team(5, 87438);
    wc.get_ith_pointless_ability(2);
    wc.add_team(73029);
    wc.get_ith_pointless_ability(4);
    wc.play_match(73029, 17555);
    wc.add_player(31855, 22669, permutation_t::read("2,3,4,1,5"), 20, 20, 20, true);
    wc.buy_team(17555, 73029);
    wc.add_team(9);
    wc.get_ith_pointless_ability(1);
    wc.add_team(3);
    wc.remove_team(73029);
    wc.play_match(5, 17555);
    wc.add_player(67014, 73029, permutation_t::read("5,2,4,1,3"), 5, 0, 12, false);
    wc.add_team(3969);
    wc.add_player_cards(7273, 4);
    wc.remove_team(9);
    wc.add_player(79764, 73029, permutation_t::read("3,1,4,5,2"), 5, 11, 0, false);
    wc.add_player(93346, 797, permutation_t::read("5,4,3,1,2"), 14, 8, 20, false);
    wc.add_player_cards(64415, 5);
    wc.num_played_games_for_player(31855);
    wc.get_ith_pointless_ability(10);
    wc.get_ith_pointless_ability(10);
    wc.add_player_cards(7929, 14);
    wc.buy_team(88, 3969);
    wc.get_ith_pointless_ability(9);
    wc.get_partial_spirit(79764);
    wc.add_player(78850, 797, permutation_t::read("4,1,2,5,3"), 24, 15, 19, true);
    wc.buy_team(5, 797);
    wc.add_player(42839, 9, permutation_t::read("3,2,4,5,1"), 10, 9, 25, false);
    wc.add_player(98295, 3969, permutation_t::read("5,3,1,2,4"), 23, 22, 21, true);
    wc.buy_team(76860, 3969);
    wc.add_player(55207, 22669, permutation_t::read("1,4,5,3,2"), 15, 23, 26, true);
    wc.add_team(54366);
    wc.add_team(72129);
    wc.add_team(65258);
    wc.add_player(36717, 54366, permutation_t::read("2,4,3,5,1"), 12, 30, 7, false);
    wc.add_player_cards(-12, 4);
    wc.add_player(79374, 3969, permutation_t::read("3,2,4,1,5"), 15, 29, 16, false);
    wc.get_team_points(54366);
    wc.add_player_cards(7273, 8);
    wc.get_partial_spirit(55207);
    wc.add_team(92737);
    wc.play_match(88, 3969);
    wc.get_partial_spirit(64415);
    wc.add_player(85133, 87438, permutation_t::read("5,1,4,3,2"), 16, 16, 22, false);
    wc.add_player(79757, 22669, permutation_t::read("5,4,3,1,2"), 2, 21, 1, false);
    wc.buy_team(22669, 73029);
    wc.add_player(78765, 92737, permutation_t::read("1,2,4,3,5"), 8, 13, 5, false);
    wc.add_player(23468, 65258, permutation_t::read("1,2,3,5,4"), 28, 12, 19, false);
    wc.add_player(70660, 797, permutation_t::read("1,2,3,4,5"), 21, 28, 68, true);
    wc.add_team(57);
    wc.add_player(77171, 3, permutation_t::read("1,2,5,4,3"), 6, 22, 3, false);
    wc.get_ith_pointless_ability(12);
    wc.get_partial_spirit(7929);
    wc.get_partial_spirit(37026);
    wc.add_player(16156, 57, permutation_t::read("2,3,1,4,5"), 6, 3, 1, false);
    wc.add_player(44051, 9, permutation_t::read("4,5,1,3,2"), 21, 23, 7, false);
    wc.get_partial_spirit(16156);
    wc.get_team_points(797);
    wc.get_team_points(5);
    wc.add_player(67032, 797, permutation_t::read("2,5,3,4,1"), 18, 27, 5, false);
    wc.play_match(73029, 17555);
    wc.get_partial_spirit(67014);
    wc.add_player(32514, 54366, permutation_t::read("2,3,4,1,5"), 25, 5, 28, true);
    wc.get_ith_pointless_ability(15);
    wc.add_player(7460, 65258, permutation_t::read("2,4,1,3,5"), 10, 10, 19, true);
    wc.add_team(6);
    wc.get_partial_spirit(31855);
    wc.remove_team(17555);
    wc.add_player_cards(7273, 14);
    wc.get_team_points(87438);
    wc.add_player(58208, 88, permutation_t::read("1,3,2,5,4"), 23, 6, 10, false);
    wc.play_match(22669, 88);
    wc.add_team(63457);
    wc.num_played_games_for_player(32514);
    wc.add_player(17231, 87438, permutation_t::read("2,3,5,1,4"), 16, 28, 21, true);
    wc.add_player(71509, 72129, permutation_t::read("3,4,2,5,1"), 26, 14, 1, false);
    wc.add_team(80119);
    wc.get_partial_spirit(70660);
    wc.add_team(1);
    wc.add_player(64151, 72129, permutation_t::read("4,5,1,3,2"), 26, 4, 23, true);
    wc.get_team_points(3969);
    wc.add_player(65786, 9, permutation_t::read("3,4,5,2,1"), 15, 29, 12, false);
    wc.buy_team(-16, 87438);
    wc.add_player_cards(16156, 3);
    wc.get_ith_pointless_ability(0);
    wc.get_ith_pointless_ability(5);
    wc.play_match(9, 88);
    wc.num_played_games_for_player(32514);
    wc.play_match(5, 63457);
    wc.add_player(11057, 87438, permutation_t::read("1,2,3,4,5"), 29, 19, 0, false);
    wc.add_player(17203, 3969, permutation_t::read("2,4,1,3,5"), 26, 3, 0, false);
    wc.play_match(9, 797);
    wc.get_ith_pointless_ability(20);
    wc.add_player(862, 1, permutation_t::read("3,5,1,2,4"), 19, 27, 9, true);
    wc.get_partial_spirit(70660);
    wc.add_player(50437, 17555, permutation_t::read("1,5,3,4,2"), 3, 26, 28, false);
    wc.get_team_points(54366);
    wc.get_ith_pointless_ability(55);
    wc.add_player(16300, 88, permutation_t::read("3,5,4,2,1"), 21, 20, 13, false);
    wc.get_ith_pointless_ability(18);
    wc.add_player(77991, 5, permutation_t::read("5,4,2,3,1"), 24, 30, 20, true);
    wc.add_player(15055, 17555, permutation_t::read("4,2,5,1,3"), 29, 6, 15, false);
    wc.add_team(6688);
    wc.add_player(55652, 92737, permutation_t::read("2,3,5,1,4"), 29, 13, 19, false);
    wc.get_ith_pointless_ability(9);
    wc.add_team(2);
    wc.get_ith_pointless_ability(10);
    wc.add_player(41205, 88, permutation_t::read("1,3,4,5,2"), 14, 1, 16, true);
    wc.get_team_points(88);
    wc.add_team(22143);
    wc.add_team(56118);
    wc.add_player(27540, 22669, permutation_t::read("4,5,3,2,1"), 16, 8, 26, false);
    wc.get_team_points(72129);
    wc.add_team(7467);
    wc.add_team(63785);
    wc.play_match(57, 54366);
    wc.get_ith_pointless_ability(13);
    wc.get_team_points(72129);
    wc.add_team(6634);
    wc.play_match(63457, 76860);
    wc.add_team(20625);
    wc.add_player(55284, 7467, permutation_t::read("4,2,5,3,1"), 1, 14, 5, true);
    wc.num_played_games_for_player(14);
    wc.add_player_cards(11057, 10);
    wc.add_player(18973, 9, permutation_t::read("4,2,5,1,3"), 30, 3, 18, false);
    wc.add_player(96342, 22143, permutation_t::read("3,4,1,5,2"), 8, 18, 23, false);
    wc.play_match(9, 87438);
    wc.add_player_cards(55652, 20);
    wc.num_played_games_for_player(16156);
    wc.add_team(84911);
    wc.play_match(797, 5);
    wc.add_team(74825);
    wc.add_team(73424);
    wc.add_team(4084);
    wc.add_team(40407);
    wc.add_player(80162, 5, permutation_t::read("4,3,2,1,5"), 11, 17, 17, false);
    wc.get_partial_spirit(17203);
    wc.get_ith_pointless_ability(18);
    wc.get_team_points(797);
    wc.add_player(31139, 65258, permutation_t::read("2,3,4,1,5"), 15, 26, 11, true);
    wc.get_ith_pointless_ability(15);
    wc.remove_team(1);
    wc.add_player(33336, 88, permutation_t::read("4,3,1,2,5"), 19, 25, 18, true);
    wc.add_player(53625, 22143, permutation_t::read("3,5,4,2,1"), 8, 11, 22, false);
    wc.add_player(63471, -16, permutation_t::read("5,1,4,2,3"), 12, 5, 1, false);
    wc.add_player(63741, 5, permutation_t::read("1,4,5,2,3"), 18, 13, 2, false);
    wc.add_player(96431, 3969, permutation_t::read("2,3,4,1,5"), 5, 13, 21, false);
    wc.add_team(82);
    wc.add_player(25941, 63457, permutation_t::read("4,5,3,2,1"), 23, 27, 13, false);
    wc.get_ith_pointless_ability(19);
    wc.play_match(73424, 22143);
    wc.add_player(30955, 82, permutation_t::read("5,3,2,4,1"), 17, 14, -11, false);
    wc.add_player(34801, 76860, permutation_t::read("2,5,3,4,1"), 30, 21, 24, false);
    wc.add_player(69384, 84911, permutation_t::read("1,5,2,4,3"), 3, 26, 8, true);
    wc.add_player(55017, 5, permutation_t::read("3,1,5,2,4"), 4, 9, 0, false);
    wc.add_player(34811, 87438, permutation_t::read("5,3,1,4,2"), 6, 23, 27, true);
    wc.get_team_points(54366);
    wc.add_player(9962, 3, permutation_t::read("4,5,2,1,3"), 29, 22, 25, false);
    wc.get_team_points(22669);
    wc.add_player(86360, 72129, permutation_t::read("4,1,2,3,5"), 5, 15, 19, true);
    wc.get_partial_spirit(79757);
    wc.add_team(78322);
    wc.add_team(2);
    wc.add_team(51806);
    wc.add_player_cards(17203, 8);
    wc.get_partial_spirit(32514);
    wc.get_partial_spirit(33336);
    wc.play_match(17555, 80119);
    wc.num_played_games_for_player(31855);
    wc.get_team_points(76860);
    wc.add_team(49756);
    wc.add_player(18529, 82, permutation_t::read("5,4,1,2,3"), 27, 4, 18, false);
    wc.add_team(4434);
    wc.add_player(13079, 63457, permutation_t::read("4,1,5,3,2"), 24, 6, 20, false);
    wc.num_played_games_for_player(64151);
    wc.get_team_points(5);
    wc.add_player(89092, 5, permutation_t::read("1,3,4,5,2"), 22, 25, 0, false);
    wc.add_player(1620, 57, permutation_t::read("3,1,4,2,5"), 21, 10, 17, true);
    wc.buy_team(63785, 74825);
    wc.play_match(1, 82);
    wc.add_player(65677, 40407, permutation_t::read("2,1,4,5,3"), 28, 28, 19, false);
    wc.get_partial_spirit(18973);
    wc.add_player(31178, 6634, permutation_t::read("5,4,1,3,2"), 1, 19, 11, false);
    wc.add_player(42961, 2, permutation_t::read("2,5,4,1,3"), 30, 18, 26, true);
    wc.num_played_games_for_player(78850);
    wc.add_player(22912, 73424, permutation_t::read("1,2,4,3,5"), 29, 14, 22, false);
    wc.add_player(19456, 22669, permutation_t::read("3,1,4,2,5"), 23, 9, 11, false);
    wc.add_player(53492, 72129, permutation_t::read("5,1,3,4,2"), 24, 0, -2, false);
    wc.get_team_points(9);
    wc.add_team(87);
    wc.play_match(3, 56118);
    wc.num_played_games_for_player(9962);
    wc.num_played_games_for_player(31178);
    wc.add_team(18009);
    wc.play_match(7467, 82);
    wc.add_player(68480, 3, permutation_t::read("3,5,2,4,1"), 10, 0, 16, false);
    wc.add_team(7431);
    wc.add_team(27765);
    wc.add_player(3875, 87438, permutation_t::read("3,4,5,1,2"), 14, 8, 12, false);
    wc.get_partial_spirit(42839);
    wc.get_partial_spirit(55284);
    wc.add_player(86651, 7431, permutation_t::read("5,4,3,2,1"), 8, 23, 3, false);
    wc.add_player(60214, 4434, permutation_t::read("5,3,4,1,2"), 21, 29, 3, false);
    wc.play_match(7467, 9);
    wc.add_team(54505);
    wc.add_player(74237, 797, permutation_t::read("2,5,4,3,1"), 10, 26, 24, false);
    wc.add_player(5455, 63785, permutation_t::read("3,1,2,4,5"), 6, 26, 20, false);
    wc.get_ith_pointless_ability(31);
    wc.add_player(32901, 3, permutation_t::read("4,1,3,2,5"), 13, 29, 7, false);
    wc.add_player(18380, 7431, permutation_t::read("1,5,4,2,3"), 22, 27, 8, false);
    wc.play_match(54366, 73029);
    wc.add_player(64633, -20, permutation_t::read("1,3,2,5,4"), 5, 27, 9, false);
    wc.add_player(6176, 5, permutation_t::read("3,4,5,2,1"), 5, 22, 22, false);
    wc.play_match(17555, 54505);
    wc.get_ith_pointless_ability(37);
    wc.add_player(2357, 54366, permutation_t::read("3,2,1,5,4"), 5, 0, 12, false);
    wc.add_team(93944);
    wc.add_player(43955, 5, permutation_t::read("3,5,2,4,1"), 18, 12, 30, false);
    wc.add_team(30016);
    wc.add_team(5);
    wc.add_player(81595, 51806, permutation_t::read("2,5,3,1,4"), 5, 8, 30, false);
    wc.remove_team(797);
    wc.get_partial_spirit(93346);
    wc.add_player(20899, 9, permutation_t::read("2,3,1,4,5"), 4, 8, 13, false);
    wc.add_player_cards(9962, 15);
    wc.add_player(9972, 56118, permutation_t::read("5,2,1,4,3"), 11, 8, 28, true);
    wc.get_ith_pointless_ability(25);
    wc.play_match(6, 82);
    wc.get_team_points(92737);
    wc.add_team(57918);
    wc.num_played_games_for_player(37026);
    wc.add_player_cards(31178, 13);
    wc.get_partial_spirit(96431);
    wc.num_played_games_for_player(77991);
    wc.remove_team(6634);
    wc.remove_team(3);
    wc.add_player_cards(68480, 0);
    wc.add_player(51037, 5, permutation_t::read("1,4,2,5,3"), 21, 9, 26, false);
    wc.add_team(2);
    wc.add_team(62603);
    wc.remove_team(40407);
    wc.add_team(83069);
    wc.add_team(7813);
    wc.add_team(5);
    wc.add_team(35393);
    wc.get_ith_pointless_ability(7);
    wc.add_player(2966, 7467, permutation_t::read("1,5,2,3,4"), 8, 4, 20, true);
    wc.num_played_games_for_player(15055);
    wc.remove_team(30016);
    wc.add_player(77811, 6, permutation_t::read("4,3,5,1,2"), 27, 25, -9, true);
    wc.add_player(62389, 83069, permutation_t::read("1,5,2,3,4"), 10, 3, 29, true);
    wc.num_played_games_for_player(862);
    wc.get_partial_spirit(85133);
    wc.num_played_games_for_player(50437);
    wc.play_match(62603, 40407);
    wc.add_team(9);
    wc.add_player(96762, 3969, permutation_t::read("2,4,3,1,5"), 20, 24, 17, true);
    wc.add_player(60241, 80119, permutation_t::read("2,3,5,1,4"), 5, 0, 0, false);
    wc.remove_team(62603);
    wc.get_ith_pointless_ability(39);
    wc.buy_team(57918, 72129);
    wc.get_partial_spirit(5151);
    wc.get_ith_pointless_ability(26);
    wc.add_player(12071, 56118, permutation_t::read("2,3,5,4,1"), 20, 24, 3, false);
    wc.add_player(75269, 57, permutation_t::read("3,5,2,4,1"), 13, 3, 29, false);
    wc.add_team(6);
    wc.get_ith_pointless_ability(6);
    wc.get_partial_spirit(2357);
    wc.add_player(15308, 7813, permutation_t::read("2,1,4,5,3"), 27, 13, 7, false);
    wc.num_played_games_for_player(55284);
    wc.remove_team(63457);
    wc.add_team(40828);
    wc.add_player(88681, 2, permutation_t::read("1,2,5,3,4"), 16, 29, 30, false);
    wc.add_player(35038, 87, permutation_t::read("2,1,3,4,5"), 25, 17, 0, false);
    wc.play_match(56118, 63457);
    wc.play_match(82, 40828);
    wc.add_player(52378, 17555, permutation_t::read("5,2,1,3,4"), 10, 7, 15, false);
    wc.get_team_points(27765);
    wc.add_player(39270, 87438, permutation_t::read("1,2,3,5,4"), 8, 26, 29, false);
    wc.get_team_points(35393);
    wc.add_player(15916, 35393, permutation_t::read("1,3,2,5,4"), 2, 3, 30, false);
    wc.get_partial_spirit(17203);
    wc.num_played_games_for_player(32514);
    wc.get_partial_spirit(75269);
    wc.add_player(57485, 72129, permutation_t::read("1,2,5,4,3"), 12, 30, 22, true);
    wc.num_played_games_for_player(89092);
    wc.add_player(16135, 83069, permutation_t::read("3,2,4,1,5"), 8, 13, 20, false);
    wc.add_team(54392);
    wc.add_team(79823);
    wc.get_team_points(87);
    wc.add_player(65270, 82, permutation_t::read("1,4,2,3,5"), 28, 27, 10, false);
    wc.add_player(58339, 83069, permutation_t::read("5,3,2,4,1"), 11, 10, 7, false);
    wc.add_player(67958, 87, permutation_t::read("4,5,3,2,1"), 5, 3, 13, false);
    wc.add_team(17738);
    wc.add_player(46211, 87, permutation_t::read("3,2,1,4,5"), 26, 28, 26, false);
    wc.get_ith_pointless_ability(34);
    wc.add_team(440);
    wc.add_player(22070, 4434, permutation_t::read("2,1,4,5,3"), 23, 8, 25, false);
    wc.add_player(33134, 9, permutation_t::read("4,5,3,2,1"), 15, 20, 13, true);
    wc.add_team(1);
    wc.add_player(251, 78322, permutation_t::read("5,3,1,2,4"), 10, 29, 29, false);
    wc.add_team(8513);
    wc.add_team(60330);
    wc.add_player(80312, 76860, permutation_t::read("4,5,3,1,2"), 22, 6, 23, false);
    wc.add_player(14698, 73029, permutation_t::read("3,2,5,1,4"), 29, 1, 8, false);
    wc.add_player(85534, 2, permutation_t::read("2,3,5,1,4"), 23, 16, 5, false);
    wc.get_team_points(57);
    wc.add_player_cards(75, 7);
    wc.add_player(11402, 74825, permutation_t::read("4,2,1,5,3"), 24, 23, 23, false);
    wc.add_player(50970, 63785, permutation_t::read("3,4,5,1,2"), 9, 23, 18, false);
    wc.add_player(75173, 3, permutation_t::read("4,1,3,5,2"), 6, 19, 19, false);
    wc.num_played_games_for_player(37026);
    wc.add_player(22635, 2, permutation_t::read("4,2,5,1,3"), 4, 15, 6, false);
    wc.get_team_points(3);
    wc.add_player(87793, 2, permutation_t::read("1,3,4,5,2"), 9, 29, 26, false);
    wc.buy_team(93944, 88);
    wc.get_team_points(22669);
    wc.add_team(3);
    wc.add_player(67579, 30016, permutation_t::read("5,4,3,1,2"), 19, 27, 26, true);
    wc.play_match(49756, 88);
    wc.get_ith_pointless_ability(54);
    wc.add_player(61437, 30016, permutation_t::read("2,1,4,3,5"), 27, 11, 22, false);
    wc.add_player(86394, 440, permutation_t::read("3,5,2,1,4"), 2, 26, 8, true);
    wc.add_player(26067, 3969, permutation_t::read("1,3,2,5,4"), 6, 15, 17, false);
    wc.remove_team(9);
    wc.add_player(60660, 1, permutation_t::read("1,5,4,2,3"), 95, 17, 0, false);
    wc.get_ith_pointless_ability(34);
    wc.get_team_points(82);
    wc.get_ith_pointless_ability(15);
    wc.get_partial_spirit(27540);
    wc.add_player(32128, 73029, permutation_t::read("5,4,1,2,3"), 12, 14, 13, false);
    wc.get_team_points(30016);
    wc.remove_team(5);
    wc.add_team(54065);
    wc.get_partial_spirit(32514);
    wc.add_player(97320, 18009, permutation_t::read("2,3,5,4,1"), 7, 5, 18, false);
    wc.get_ith_pointless_ability(31);
    wc.num_played_games_for_player(70660);
    wc.get_team_points(3);
    wc.num_played_games_for_player(52378);
    wc.add_player(45198, 1, permutation_t::read("3,2,1,4,5"), 3, 15, 21, false);
    wc.add_player(9391, 54366, permutation_t::read("2,5,1,3,4"), 28, 9, 5, false);
    wc.add_player(40657, 57, permutation_t::read("1,3,5,4,2"), 73, 16, 0, false);
    wc.add_player(11868, 56118, permutation_t::read("4,1,5,3,2"), 16, 0, 27, true);
    wc.num_played_games_for_player(52378);
    wc.buy_team(30016, 87);
    wc.add_player(59550, 9, permutation_t::read("2,4,1,3,5"), 12, 8, 23, false);
    wc.add_player(78052, 6634, permutation_t::read("5,1,4,2,3"), 7, 24, 14, false);
    wc.get_team_points(57);
    wc.add_player(7190, 18009, permutation_t::read("1,4,2,5,3"), 7, 10, 9, false);
    wc.buy_team(57, 9);
    wc.add_team(99867);
    wc.add_player(40503, 51806, permutation_t::read("1,4,5,3,2"), 0, 20, 6, false);
    wc.remove_team(54392);
    wc.num_played_games_for_player(79374);
    wc.add_player(79792, 87438, permutation_t::read("3,5,4,2,1"), 13, 20, 27, true);
    wc.add_player(49402, 54392, permutation_t::read("3,5,2,1,4"), 9, 9, 5, false);
    wc.add_player(69979, 87, permutation_t::read("2,4,5,3,1"), 16, 30, 12, false);
    wc.add_player(34995, 1, permutation_t::read("4,2,5,1,3"), 5, 1, 26, true);
    wc.num_played_games_for_player(96431);
    wc.add_player(95206, 40828, permutation_t::read("5,1,3,4,2"), 18, 0, 1, false);
    wc.get_team_points(-3);
    wc.add_team(81633);
    wc.play_match(99867, 54366);
    wc.add_player(19725, 9, permutation_t::read("5,4,2,1,3"), 22, 8, 21, false);
    wc.play_match(84911, 84911);
    wc.add_player(1710, 76860, permutation_t::read("1,2,5,4,3"), 36, 11, 17, false);
    wc.get_partial_spirit(40657);
    wc.add_player(78961, 73029, permutation_t::read("4,5,2,3,1"), 8, 18, 13, true);
    wc.add_team(83722);
    wc.add_team(1);
    wc.add_player(25270, 57918, permutation_t::read("3,1,2,4,5"), 17, 26, 17, false);
    wc.get_partial_spirit(13079);
    wc.add_player(28487, 82, permutation_t::read("5,1,2,4,3"), 5, 24, 3, false);
    wc.get_team_points(20625);
    wc.play_match(22143, 87);
    wc.add_player(28924, 1, permutation_t::read("4,1,2,5,3"), 15, 6, 21, false);
    wc.add_player(60460, 6634, permutation_t::read("3,1,5,4,2"), 0, 9, 11, false);
    wc.add_player(94981, 7431, permutation_t::read("3,1,4,5,2"), 5, 18, 29, false);
    wc.add_team(35971);
    wc.remove_team(8513);
    wc.play_match(76860, 83069);
    wc.add_player(86931, 56118, permutation_t::read("4,2,3,1,5"), 3, 23, 8, false);
    wc.add_team(7);
    wc.remove_team(1);
    wc.buy_team(81633, 2);
    wc.add_player(56727, 87, permutation_t::read("2,5,1,4,3"), 28, 6, 30, false);
    wc.add_player(3422, 60330, permutation_t::read("3,2,1,4,5"), 14, 9, 16, false);
    wc.play_match(60330, 60330);
    wc.add_player(49830, 6688, permutation_t::read("2,4,1,3,5"), 28, 2, 11, false);
    wc.add_player(66919, 83722, permutation_t::read("4,3,2,5,1"), 10, 25, 27, true);
    wc.remove_team(81633);
    wc.add_player(42549, 78322, permutation_t::read("1,2,3,5,4"), 20, 27, 29, true);
    wc.play_match(74825, 8513);
    wc.add_player_cards(1710, 16);
    wc.add_player(66538, 57, permutation_t::read("2,4,3,1,5"), 30, 30, 2, false);
    wc.num_played_games_for_player(80312);
    wc.add_player_cards(60241, 19);
    wc.get_ith_pointless_ability(5);
    wc.get_ith_pointless_ability(7);
    wc.add_player(49973, 40828, permutation_t::read("1,4,3,2,5"), 20, 1, 26, false);
    wc.get_partial_spirit(95206);
    wc.add_player(82310, 3, permutation_t::read("3,4,5,1,2"), 11, 27, 0, false);
    wc.add_player(77008, 93944, permutation_t::read("3,1,2,4,5"), 13, 9, 9, true);
    wc.add_team(88981);
    wc.remove_team(60330);
    wc.add_team(1);
    wc.add_player(61801, 40828, permutation_t::read("3,5,2,4,1"), 10, 28, 28, false);
    wc.add_team(1981);
    wc.add_player(68713, 87438, permutation_t::read("3,4,2,5,1"), 6, 8, 23, false);
    wc.add_player(52968, 99867, permutation_t::read("3,1,2,5,4"), 18, 28, 24, false);
    wc.add_player(51000, 35393, permutation_t::read("5,2,3,4,1"), 13, 10, 16, false);
    wc.num_played_games_for_player(86651);
    wc.add_player_cards(15916, 27);
    wc.add_player_cards(53492, 17);
    wc.play_match(80119, 17738);
    wc.num_played_games_for_player(64633);
    wc.add_player(57079, 72129, permutation_t::read("2,1,4,5,3"), 14, 20, 7, false);
    wc.add_player(6993, 79823, permutation_t::read("1,5,2,3,4"), 16, 30, 13, true);
    wc.get_partial_spirit(22070);
    wc.get_partial_spirit(51000);
    wc.add_player(75306, 4084, permutation_t::read("5,1,2,3,4"), 2, 16, 2, false);
    wc.add_player_cards(22070, 27);
    wc.add_team(81220);
    wc.add_player(76182, 4084, permutation_t::read("1,3,2,5,4"), 21, 25, 8, false);
    wc.num_played_games_for_player(31855);
    wc.add_player(47428, 81220, permutation_t::read("1,3,4,2,5"), 5, 6, 24, false);
    wc.add_player(90891, 8513, permutation_t::read("4,3,2,1,5"), 14, 28, 21, false);
    wc.play_match(0, 7813);
    wc.get_partial_spirit(42839);
    wc.play_match(6688, 6);
    wc.num_played_games_for_player(51000);
    wc.remove_team(65258);
    wc.add_player_cards(30955, 11);
    wc.get_partial_spirit(66538);
    wc.add_player(13011, 73424, permutation_t::read("5,3,1,2,4"), 1, 14, 25, true);
    wc.add_team(63338);
    wc.play_match(78322, 54505);
    wc.add_player(5112, 40828, permutation_t::read("3,2,4,1,5"), 25, 13, 30, true);
    wc.add_team(9);
    wc.buy_team(1981, 99867);
    wc.add_player_cards(22070, 28);
    wc.add_player(84175, 6, permutation_t::read("2,5,3,1,4"), 29, 7, 9, true);
    wc.add_team(2);
    wc.add_player(54958, 7, permutation_t::read("2,3,4,5,1"), 7, 4, 21, true);
    wc.buy_team(49756, 30016);
    wc.add_team(77088);
    wc.add_team(46680);
    wc.add_player(70629, 22669, permutation_t::read("4,5,2,3,1"), 27, 24, 29, true);
    wc.buy_team(5, 1);
    wc.add_player(92709, 62603, permutation_t::read("5,1,4,2,3"), 15, 3, 11, false);
    wc.add_team(55510);
    wc.add_player(88430, 27765, permutation_t::read("1,2,4,5,3"), 1, 5, 21, true);
    wc.get_ith_pointless_ability(2);
    wc.add_player(48, 92737, permutation_t::read("5,1,3,2,4"), 11, 15, 30, false);
    wc.add_player(92756, 7, permutation_t::read("1,5,2,4,3"), 23, 16, 24, false);
    wc.add_player(64918, 7, permutation_t::read("2,1,3,5,4"), 23, 25, 1, false);
    wc.add_player(92169, 88981, permutation_t::read("4,3,5,2,1"), 16, 13, 7, false);
    wc.get_team_points(6);
    wc.add_team(154);
    wc.add_player(9989, 63785, permutation_t::read("2,1,4,3,5"), 4, 18, 30, true);
    wc.get_team_points(7431);
    wc.add_team(23996);
    wc.add_team(86922);
    wc.add_player(16685, 57, permutation_t::read("5,3,4,1,2"), 7, 15, 10, false);
    wc.add_player(42112, 4434, permutation_t::read("1,5,2,4,3"), 23, 25, 24, true);
    wc.get_partial_spirit(56);
    wc.get_partial_spirit(2357);
    //----------------------------------------------------------------------------------------------------------
    wc.buy_team(27765, 76860);
    //----------------------------------------------------------------------------------------------------------
    wc.num_played_games_for_player(80162);
    wc.add_player(44248, 55510, permutation_t::read("4,5,1,3,2"), 19, 6, 30, false);
    wc.add_player(67258, 9, permutation_t::read("1,5,3,2,4"), 12, 28, 6, false);
    wc.add_player(67280, 1981, permutation_t::read("1,2,5,4,3"), 15, 23, 15, false);
    wc.play_match(1, 88);
    wc.get_team_points(5);
    wc.get_partial_spirit(75173);
    wc.remove_team(1);
    wc.add_player_cards(96839, 15);
    wc.add_player(16911, 55510, permutation_t::read("3,5,1,4,2"), 4, 30, 17, true);
    wc.add_player(70212, 87438, permutation_t::read("3,4,2,1,5"), 4, 9, 22, true);
    wc.add_player(4557, 1, permutation_t::read("3,4,5,1,2"), 19, 26, 8, false);
    wc.get_partial_spirit(68480);
    wc.add_team(18669);
    wc.remove_team(30016);
    wc.add_player(88263, 3, permutation_t::read("5,3,4,1,2"), 1, 6, 5, false);
    wc.get_ith_pointless_ability(44);
    wc.add_player_cards(60241, 0);
    wc.add_team(91864);
    wc.add_player_cards(69979, 4);
    wc.get_ith_pointless_ability(71);
    wc.add_team(14925);
    wc.add_player(47202, 74825, permutation_t::read("2,1,4,5,3"), 15, 0, 30, true);
    wc.play_match(86922, 72129);
    wc.add_team(10358);
    wc.get_team_points(62603);
    wc.add_player(29436, 73029, permutation_t::read("3,5,1,2,4"), 10, 6, 11, false);
    wc.get_ith_pointless_ability(18);
    wc.add_player(92262, 83069, permutation_t::read("2,5,3,1,4"), 10, 19, 16, false);
    wc.add_player(38273, 797, permutation_t::read("2,5,3,1,4"), 22, 26, 24, true);
    wc.play_match(54065, 56);
    wc.add_player(89496, 1, permutation_t::read("2,5,3,1,4"), 23, 7, 21, false);
    wc.get_partial_spirit(78052);
    wc.add_team(57567);
    wc.add_player(22145, 5, permutation_t::read("4,5,1,3,2"), 8, 10, 14, false);
    wc.add_player(68055, 63457, permutation_t::read("5,2,4,1,3"), 14, 16, 22, false);
    wc.add_player(54696, 57, permutation_t::read("2,5,3,4,1"), 22, 7, 27, false);
    wc.get_ith_pointless_ability(60);
    wc.add_player(2243, 73424, permutation_t::read("1,5,4,3,2"), 10, 29, 15, false);
    wc.add_player(98919, 6688, permutation_t::read("4,2,5,3,1"), 0, 2, 7, false);
    wc.buy_team(3, 57);
    wc.add_player(4421, 6, permutation_t::read("3,2,4,5,1"), 7, 5, 6, false);
    wc.add_player(21567, 57918, permutation_t::read("3,4,5,2,1"), 17, 29, 18, true);
    wc.add_team(53543);
    wc.get_ith_pointless_ability(71);
    wc.add_player(67170, 35393, permutation_t::read("3,1,4,5,2"), 7, 5, 0, false);
    wc.get_partial_spirit(65786);
    wc.get_partial_spirit(46211);
    wc.add_player_cards(69384, 8);
    wc.add_player(76071, 63338, permutation_t::read("1,3,5,4,2"), 41, 22, 8, false);
    wc.add_player(11112, 6634, permutation_t::read("5,2,3,1,4"), 19, 20, 23, false);
    wc.add_player(65770, 21, permutation_t::read("2,3,1,4,5"), 26, 28, 0, true);
    wc.buy_team(22143, 35971);
    wc.play_match(87, 3969);
    wc.get_partial_spirit(49402);
    wc.buy_team(4084, 82);
    wc.add_player(71716, 82, permutation_t::read("1,5,2,3,4"), 5, 17, 23, false);
    wc.remove_team(57);
    wc.get_team_points(20625);
    wc.get_partial_spirit(34801);
    wc.add_player(17650, 57567, permutation_t::read("3,1,5,2,4"), 0, 29, 23, true);
    wc.add_team(17983);
    wc.play_match(20625, 20625);
    wc.add_team(75844);
    wc.play_match(5, 35971);
    wc.get_partial_spirit(54);
    wc.get_ith_pointless_ability(22);
    wc.add_player(50274, 63457, permutation_t::read("1,4,3,2,5"), 18, 13, 13, false);
    wc.add_player(17319, 87, permutation_t::read("5,3,2,4,1"), 8, 4, 2, false);
    wc.add_player(5033, 18009, permutation_t::read("1,2,3,4,5"), 6, 28, 30, false);
    wc.get_partial_spirit(16300);
    wc.get_partial_spirit(54696);
    wc.add_team(14088);
    wc.add_player(28910, 1, permutation_t::read("4,5,1,3,2"), 33, 20, 10, true);
    wc.get_team_points(73424);
    wc.add_player(35885, 4084, permutation_t::read("1,3,2,4,5"), 4, 21, 27, false);
    wc.add_team(99939);
    wc.add_player(41374, 83722, permutation_t::read("1,2,4,5,3"), 21, 5, 26, false);
    wc.add_player(44076, 80119, permutation_t::read("2,3,4,5,1"), 28, 19, 29, false);
    wc.buy_team(9, 46680);
    wc.add_player(92808, 57, permutation_t::read("1,4,2,3,5"), 28, 11, 8, false);
    wc.add_player(44047, 154, permutation_t::read("3,4,2,5,1"), 30, 22, 18, false);
    wc.get_ith_pointless_ability(3);
    wc.add_player(26872, 14925, permutation_t::read("2,4,5,3,1"), 20, 14, 23, true);
    wc.add_player(85084, 1, permutation_t::read("5,3,4,1,2"), 13, 4, 29, false);
    wc.get_partial_spirit(20093);
    wc.get_partial_spirit(82310);
    wc.add_player(94751, 82, permutation_t::read("2,3,4,5,1"), 5, 18, 25, true);
    wc.get_partial_spirit(42549);
    wc.add_player(82319, 81633, permutation_t::read("3,4,2,5,1"), 9, 15, 11, false);
    wc.get_partial_spirit(89092);
    wc.get_partial_spirit(2243);
    wc.add_team(8);
    wc.add_player_cards(35038, 70);
    wc.get_ith_pointless_ability(35);
    wc.add_team(26416);
    wc.add_player(66204, 54065, permutation_t::read("4,1,5,2,3"), 28, 16, 29, false);
    wc.play_match(18669, 17983);
    wc.add_team(16312);
    wc.get_ith_pointless_ability(82);
    wc.add_player(16692, 63457, permutation_t::read("5,4,3,2,1"), 16, 1, 7, false);
    wc.add_player(89077, 6, permutation_t::read("5,3,4,2,1"), 16, 5, 24, true);
    wc.add_player(39388, 72129, permutation_t::read("1,5,3,4,2"), 21, 17, 9, false);
    wc.get_team_points(3);
    wc.remove_team(99867);
    wc.add_team(71845);
    wc.add_player(47769, 30016, permutation_t::read("3,5,4,2,1"), 19, 14, 8, false);
    wc.add_team(85);
    wc.get_team_points(78322);
    wc.add_player(6109, 30016, permutation_t::read("2,3,4,1,5"), 10, 21, 3, false);
    wc.get_partial_spirit(68713);
    wc.buy_team(92737, 65258);
    wc.get_ith_pointless_ability(62);
    wc.add_team(71441);
    wc.add_team(32849);
    wc.num_played_games_for_player(38273);
    wc.add_team(75504);
    wc.add_team(33573);
    wc.add_player(78968, 8, permutation_t::read("5,1,3,4,2"), 24, 14, 9, false);
    wc.get_partial_spirit(55);
    wc.add_player(78111, 91, permutation_t::read("4,2,1,5,3"), 12, 21, 29, false);
    wc.add_player(31455, 54065, permutation_t::read("3,1,2,4,5"), 27, 20, 4, false);
    wc.add_player_cards(11868, 22);
    wc.num_played_games_for_player(57485);
    wc.play_match(18009, 8);
    wc.add_player(83790, 23996, permutation_t::read("2,5,4,1,3"), 16, 23, 23, false);
    wc.add_player(65220, 88, permutation_t::read("2,4,5,1,3"), 14, 6, 7, true);
    wc.get_ith_pointless_ability(86);
    wc.add_team(1566);
    wc.get_ith_pointless_ability(89);
    wc.get_team_points(9);
    wc.get_ith_pointless_ability(7);
    wc.get_ith_pointless_ability(14);
    wc.get_ith_pointless_ability(35);
    wc.add_player_cards(14698, 19);
    wc.num_played_games_for_player(92262);
    wc.remove_team(71845);
    wc.add_player(71017, 8513, permutation_t::read("5,4,2,1,3"), 24, 27, 19, true);
    wc.remove_team(95);
    wc.add_team(21972);
    wc.add_team(34674);
    wc.get_team_points(18009);
    wc.get_team_points(5);
    wc.add_team(31824);
    wc.add_player(87152, 73424, permutation_t::read("2,5,4,1,3"), 4, 29, 12, true);
    wc.add_player(23883, 1, permutation_t::read("2,4,5,1,3"), 18, 6, 21, false);
    wc.get_team_points(2);
    wc.add_player_cards(67280, 22);
    wc.add_player_cards(32901, 12);
    wc.get_ith_pointless_ability(45);
    wc.add_team(94219);
    wc.add_player(43980, 20625, permutation_t::read("3,4,2,5,1"), 22, 3, 29, false);
    wc.add_player(49758, 34674, permutation_t::read("4,1,2,5,3"), 0, 10, 12, false);
    wc.buy_team(88, 87);
    wc.add_player(41653, 6634, permutation_t::read("3,5,4,1,2"), 18, 0, 15, false);
    wc.get_team_points(17555);
    wc.play_match(57567, 22669);
    wc.add_player(34285, 6, permutation_t::read("5,2,3,1,4"), 13, 23, 46, false);
    wc.get_team_points(9);
    wc.get_partial_spirit(41374);
    wc.add_player(32233, 8, permutation_t::read("4,1,3,5,2"), 2, 13, 6, false);
    wc.add_player(30248, 79823, permutation_t::read("2,1,3,4,5"), 15, 25, 26, false);
    wc.get_ith_pointless_ability(33);
    wc.remove_team(4434);
    wc.play_match(87, 63338);
    wc.add_player(90286, 31824, permutation_t::read("4,2,5,3,1"), 13, 18, 18, true);
    wc.get_ith_pointless_ability(16);
    wc.add_player(87293, 82, permutation_t::read("5,4,2,1,3"), 15, 1, 7, false);
    wc.num_played_games_for_player(21567);
    wc.add_player(84111, 7431, permutation_t::read("3,4,2,1,5"), 21, 19, 21, true);
    wc.add_team(41206);
    wc.add_player(45738, 14088, permutation_t::read("4,2,5,1,3"), 10, 26, 0, false);
    wc.add_player(34306, 57567, permutation_t::read("2,5,1,3,4"), 27, 17, 17, false);
    wc.num_played_games_for_player(86360);
    wc.get_ith_pointless_ability(88);
    wc.add_player(22420, 40, permutation_t::read("4,1,5,3,2"), 15, 4, 20, true);
    wc.add_player(68, 3969, permutation_t::read("1,2,3,5,4"), 3, 24, 11, false);
    wc.remove_team(17983);
    wc.add_player(7163, 54366, permutation_t::read("5,3,2,1,4"), 9, 29, 5, false);
    wc.remove_team(30016);
    wc.add_team(70740);
    wc.add_player_cards(58208, 10);
    wc.add_player_cards(67958, 22);
    wc.add_player(5134, 7813, permutation_t::read("3,1,4,2,5"), 5, 27, 3, false);
    wc.get_team_points(72129);
    wc.add_player(42504, 57, permutation_t::read("3,2,5,4,1"), 16, 5, 6, false);
    wc.add_team(23153);
    wc.add_player(30041, 49756, permutation_t::read("5,4,1,2,3"), 5, 28, 11, false);
    wc.add_player(11541, 35393, permutation_t::read("2,5,4,3,1"), 16, 26, 16, false);
    wc.add_player(33732, 34674, permutation_t::read("4,2,1,5,3"), 17, 54, 24, true);
    wc.get_ith_pointless_ability(59);
    wc.play_match(18669, 19);
    wc.get_partial_spirit(82319);
    wc.get_team_points(94219);
    wc.add_team(3713);
    wc.add_player(45880, 16312, permutation_t::read("5,1,3,4,2"), 30, 23, 5, false);
    wc.play_match(3, 62603);
    wc.num_played_games_for_player(22420);
    wc.add_player(61163, 33573, permutation_t::read("1,3,5,2,4"), 24, 20, 12, true);
    wc.add_player(21786, 3, permutation_t::read("2,4,1,5,3"), 13, 15, 19, false);
    wc.add_player(95320, 6, permutation_t::read("4,5,3,2,1"), 0, 26, 20, false);
    wc.get_team_points(3);
    wc.add_team(10909);
    wc.add_player(19930, 23996, permutation_t::read("4,1,2,5,3"), 24, 6, 14, true);
    wc.play_match(73424, 54392);
    wc.get_ith_pointless_ability(66);
    wc.add_player(37837, 3969, permutation_t::read("3,2,5,1,4"), 26, 0, 16, false);
    wc.get_ith_pointless_ability(28);
    wc.get_partial_spirit(65786);
    wc.get_ith_pointless_ability(21);
    wc.add_team(7184);
    wc.add_player(67, 35971, permutation_t::read("4,3,2,1,5"), 20, 24, 27, false);
    wc.add_player(43660, 3969, permutation_t::read("2,5,3,4,1"), 6, 15, 9, false);
    wc.get_ith_pointless_ability(57);
    wc.add_player(68112, 9, permutation_t::read("2,5,4,1,3"), 20, 6, 14, false);
    wc.add_player(80354, 27765, permutation_t::read("1,5,4,3,2"), 20, 12, 28, false);
    wc.add_player(84378, 40828, permutation_t::read("5,1,2,4,3"), 29, 4, 20, false);
    wc.add_player(54477, 86922, permutation_t::read("5,1,2,3,4"), 5, 23, 9, false);
    wc.add_player(45562, 4084, permutation_t::read("3,2,1,4,5"), 22, 20, 18, false);
    wc.add_player_cards(7460, 22);
    wc.add_team(92877);
    wc.add_team(25468);
    wc.num_played_games_for_player(31855);
    wc.add_player(58005, 53543, permutation_t::read("4,3,2,1,5"), 1, 2, 4, false);
    wc.get_partial_spirit(862);
    wc.add_team(46452);
    wc.add_player(17313, 57, permutation_t::read("3,5,1,2,4"), 8, 6, 4, true);
    wc.add_team(49439);
    wc.get_team_points(32849);
    wc.get_partial_spirit(53492);
    wc.get_partial_spirit(96431);
    wc.get_team_points(82);
    wc.play_match(93944, 7467);
    wc.add_player(96944, 83722, permutation_t::read("1,4,3,5,2"), 45, 3, 18, true);
    wc.add_player(25949, 55510, permutation_t::read("5,4,2,1,3"), 13, 16, 18, false);
    wc.add_team(27988);
    wc.get_partial_spirit(40657);
    wc.get_ith_pointless_ability(-2);
    wc.add_player(81077, 2, permutation_t::read("5,1,2,4,3"), 26, 14, 25, true);
    wc.get_ith_pointless_ability(52);
    wc.get_team_points(54392);
    wc.add_player_cards(44076, 8);
    wc.add_team(16345);
    wc.remove_team(79823);
    wc.add_player(13161, 4434, permutation_t::read("1,3,2,4,5"), 11, 15, 1, false);
    wc.remove_team(93944);
    wc.add_player_cards(65677, 10);
    wc.get_ith_pointless_ability(35);

    return 0;
}