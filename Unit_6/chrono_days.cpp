/*************************************************************************
	> File Name: chrono_days.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月13日 星期六 08时28分14秒
 ************************************************************************/

#include<iostream>
#include<chrono>
#include<ratio>
using namespace std;

int main()
{
    using namespace std::chrono;
    typedef duration<int,std::ratio<60*60*24>> days_type;

    time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());

    cout << today.time_since_epoch().count() << " days since epoch" << endl;

    return 0;
}
