#include <iostream>
using namespace std;
struct Coon
{
    unsigned int id;
    char name[100];
    double weight;
    double food;
};
Coon *find_the_most_fed_cat(Coon *atc, unsigned int n_cats);
// Место для вашего кода.

Coon *find_the_most_fed_cat(Coon *atc, unsigned int n_cats)
{
    // result указывает на текущего лидера прямо внутри исходного массива.
    Coon *result = &atc[0];
    double compare_criterion = result->food / result->weight;
    for (unsigned int i = 1; i < n_cats; ++i)
    {
        double this_compare_criterion = atc[i].food / atc[i].weight;
        if (this_compare_criterion > compare_criterion)
        {
            compare_criterion = this_compare_criterion;
            result = &atc[i];
        }
    }

    return result;
}

int main()
{
    Coon all_the_coons[1000];
    unsigned int n;
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
        cin >> all_the_coons[i].id >> all_the_coons[i].name >> all_the_coons[i].weight >> all_the_coons[i].food;
    cout << find_the_most_fed_cat(all_the_coons, n)->name << endl;
    return 0;
}
