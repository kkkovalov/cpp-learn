#include <iostream>

struct Ad
{
    int watchedTimes{};
    int percentageClicked{};
    int avgEarnings{};
};

void revenueCalculator(const Ad &curAd)
{
    std::cout << "Ad was watched: " << curAd.watchedTimes << " times.\n";
    std::cout << "Out of 100 users, " << curAd.percentageClicked << " users clicked on ad.\n";
    std::cout << "Average earning per click: " << curAd.avgEarnings << '\n';
    std::cout << "Total revenue is: " << curAd.watchedTimes * curAd.percentageClicked / 100 * curAd.avgEarnings << '\n';
};

int main()
{
    Ad newAd{};
    std::cin >> newAd.watchedTimes >> newAd.percentageClicked >> newAd.avgEarnings;
    revenueCalculator(newAd);
}
