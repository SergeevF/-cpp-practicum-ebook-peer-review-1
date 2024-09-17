#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

namespace LibraryUser{
void Read(unsigned int user, unsigned int page, vector<unsigned int>& user_id_to_num_page, vector<unsigned int>& pages_to_num_of_users){
    size_t i = 1;
    if(user_id_to_num_page.size() > user) i = user_id_to_num_page[user] > 0 ? user_id_to_num_page[user]+1 : 1;
    else i = 1;

    for(; i <=  page; ++i)
        ++pages_to_num_of_users[i];

    user_id_to_num_page[user] = page;
}

double Cheer(unsigned int user, vector<unsigned int>& user_id_to_num_page, vector<unsigned int>& pages_to_num_of_users){
    auto page_number = user_id_to_num_page[user];
    if (page_number == 0) return 0;
    if (pages_to_num_of_users[1] == 1) return 1;
    auto users_number = pages_to_num_of_users[page_number];
    return 1.0 - (users_number - 1.0) / (pages_to_num_of_users[1] - 1.0);
}
}
int main()
{
    unsigned int user = 0;
    unsigned int page = 0;

    vector<unsigned int> user_id_to_num_page(10e5+1);
    vector<unsigned int> pages_to_num_of_users(1001);
    unsigned int num = 0;
    cin >> num;
    string command = {};
    for(size_t i = 0; i < num; ++i){
        cin >> command;
        if (command == "READ"s) {
            cin >> user >> page;
            LibraryUser::Read(user, page, user_id_to_num_page, pages_to_num_of_users);
        } else if (command == "CHEER"s) {
            cin >> user;

            cout << setprecision(6) << LibraryUser::Cheer(user, user_id_to_num_page, pages_to_num_of_users)<<endl;
        }

    }

    return 0;
}
