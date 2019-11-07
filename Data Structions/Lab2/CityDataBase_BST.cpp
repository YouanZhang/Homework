#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef int DB;
class Point {
private:
    DB x, y;
public:
    Point (DB _x, DB _y) : x(_x), y(_y) {}
    DB getX() {return x;}
    DB getY() {return y;}
    DB distanceWith(Point a) {return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));}
    bool operator == (Point a) {return x == a.x && y == a.y;}
    Point () {}
};
typedef string Name;
class City {
private:
    Point coordinate;
    Name name;
    City *leftSon, *rightSon, *father;
public:
    City (string _name, Point _coordinate, City* _father) : name(_name), coordinate(_coordinate), leftSon(nullptr), rightSon(nullptr), father(_father) {}
    void setName(string &_name) {name = _name;}
    void setCoodinate(Point &_coordinate) {coordinate = _coordinate;}
    void setLeftSon(City *_leftSon) {leftSon = _leftSon;}
    void setRightSon(City *_rightSon) {rightSon = _rightSon;}
    void setFather(City *_father) {father = _father;}
    string getName() {return name;}
    Point getCoordinate() {return coordinate;}
    City *getLeftSon() {return leftSon;}
    City *getRightSon() {return rightSon;}
    City *getFather() {return father;}
};
class CityDataBase {
private:
    City *city;
    string Ope[5] = {"", "Insert", "Delete", "Search", "Exit"};
    string Typ[3] = {"", "name", "coordinate"};
public:
    CityDataBase () {
        city = new City("", Point(0, 0));
    }

    void printFirstLevelUi() {
        cout << "Choose your operation (index):" << endl;
        for (int i = 1; i <= 4; i++) cout << i << " : " << Ope[i] << endl;
    }

    void printSecondLevelUi(string ope) {
        cout << "Choose your " << ope << " type (index):" << endl;
        for (int i = 1; i <= 2; i++) cout << i << " : By " << Typ[i] << endl;
    }

    City *pointSearchByName(string tmpname) {
        for (City *root = this->city; root != nullptr; root = tmpname < root->getName() ? root->getLeftSon() : root->getRightSon())
            if (root->getName() == tmpname) return root;
        return nullptr; // error
    }

    City *pointSearchByCoordinate(Point tmpcoordinate, City *root) {
        if (root == nullptr) return root;
        if (root->getCoordinate() == tmpcoordinate) return root;
        City *tmpcity = pointSearchByCoordinate(tmpcoordinate, root->getLeftSon());
        if (tmpcity != nullptr) return tmpcity;
        return pointSearchByCoordinate(tmpcoordinate, root->getRightSon());
    }

    void pointSearch() {
        printSecondLevelUi("search");
        int typ;
        cin >> typ;
        City *tmpcity;
        if (typ == 1) {
            cout << "Enter city name: " << endl;
            string tmpname;
            cin >> tmpname;
            tmpcity = pointSearchByName(tmpname);
            if (tmpcity != nullptr) cout << "It it located ( " << tmpcity->getCoordinate().getX() << " , " << tmpcity->getCoordinate().getY() << " )." << endl;
            else cout << "SEARCH ERROR" << endl << "Please check your city name." << endl;
        }
        if (typ == 2) {
            cout << "Enter city coordinate: (e.g. 1 1):" << endl;
            DB tmpx, tmpy;
            tmpcity = pointSearchByCoordinate(Point(tmpx, tmpy));
            if (tmpcity != nullptr) cout << "It is " << tmpcity->getName() << endl;
            else cout << "SEARCH ERROR" << endl << "Please check your city coordinate." << endl;
        }
    }

    int rangeSearchDFS(City *c, Point center, DB r) {
        if (*c == nullptr) return 0;
        int cnt = 0;
        if (c->getCoordinate().distanceWith(center) <= r) {
            cnt++;
            cout << c->getName() << " ( " << c->getCoordinate().getX() << " , " << c->getCoordinate().getY() << " )" << endl;
        }
        cnt += rangeSearchDFS(c->getLeftSon(), center, r);
        cnt += rangeSearchDFS(c->getRightSon(), center, r);
        return cnt;
    }

    void rangeSearch() {
        cout << "Enter your coodinate (e.g. 1 1):" << endl;
        DB tmpx, tmpy;
        cin >> tmpx >> tmpy;
        Point center(tmpx, tmpy);
        cout << "Enter your search radius :" << endl;
        DB tmpr;
        cin >> tmpr;
        int cnt = 0;
        rangeSearchDFS(this->city, center, tmpr);
        cout << "Total :" << cnt << endl;
    }

    void search() {
        cout << "Choose your search mode :" << endl;
        cout << "1 : Point search" << endl;
        cout << "2 : Range search" << endl;
        int mode;
        cin >> mode;
        if (mode == 1) pointSearch();
        if (mode == 2) rangeSearch();
    }

    void insertByName() {
        cout << "Enter city name: " << endl;
        string tmpname;
        cin >> tmpname;
        cout << "Enter city coordinate (e.g. 1 1):" << endl;
        DB tmpx, tmpy;
        cin >> tmpx >> tmpy;
        if (!pointSearchByName(tmpname) && !pointSearchByCoordinate(Point(tmpx, tmpy), this->city)) {
            City *root = this->city, **leave = &root, *father = root;
            for (; *leave != nullptr; ) {
                if (tmpname < (*leave)->getName()) {
                    auto k = (*leave)->getLeftSon();
                    leave = &k;
                }
                else {
                    auto k = (*leave)->getRightSon();
                    leave = &k;
                } 
                father = *leave;
            }
            // for (; *leave != nullptr; leave = (tmpname < (*leave)->getName() ? &((*leave)->getLeftSon()) : &((*leave)->getRightSon())));
            *leave = new City(tmpname, Point(tmpx, tmpy), father);
        }
        else cout << "INSERT ERROR" << endl << "Please check your city name and coordinate." << endl;
    }

    // void insertByCoordinate() {
    //     cout << "Enter city coordinate (e.g. 1 1):" << endl;
    //     DB tmpx, tmpy;
    //     cin >> tmpx >> tmpy;
    //     cout << "Enter city name: " << endl;
    //     string tmpname;
    //     cin >> tmpname;
    //     if (pointSearchByName(tmpname) == -1 && pointSearchByCoordinate(Point(tmpx, tmpy)) == -1) city.push_back(City(tmpname, Point(tmpx, tmpy)));
    //     else cout << "INSERT ERROR" << endl << "Please check your city name and coordinate." << endl;
    // }

    void insert() {
        // printSecondLevelUi("insert");
        // int typ;
        // cin >> typ;
        // if (typ == 1) insertByName();
        // if (typ == 2) insertByCoordinate();
        insertByName();
    }

    void deletTmpCity(City *tmpcity) {
        City *tagcity = tmpcity;
        if (tmpcity->getLeftSon() != nullptr) {
            for (tagcity = tmpcity->getLeftSon(); tagcity->getRightSon() != nullptr;tagcity = tagcity->getRigthSon());
        }
        else if (tmpcity->getRightSon() != nullptr) {
            for (tagcity = tmpcity->getRightSon(); tagcity->getLeftSon() != nullptr;tagcity = tagcity->getLeftSon());
        }
        if (tagcity->getFather()->getLeftSon() == tagcity) tagcity->getFather(->getLeftSon() = nullptr;
        else tagcity->getFather()->getRightSon() = nullptr;
        if (tmpcity->getFather()->getLeftSon() == tmpcity) {
            if (tagcity == tmpcity) tmpcity->getFather()->getLeftSon() = nullptr;
            else tmpcity->getFather()->getLeftSon() = tagcity;
        }
        else {
            if (tagcity == tmpcity) tmpcity->getFather()->getRightSon() = nullptr;
            else tmpcity->getFather()->getRightSon() = tagcity;
        }
        tagcity->setLeftSon() = tmpcity->getLeftSon();
        tagcity->setRightSon() = tmpcity->getRightSon();
        tagcity->setFather() = tmpcity->getFather;
        delete tmpcity;
    }
    void deletByName() {
        cout << "Enter city name :" << endl;
        string tmpname;
        cin >> tmpname;
        City *tmpcity = pointSearchByName(tmpname);
        if (tmpcity != nullptr) deletTmpCity(tmpcity);
        else cout << "DELETE ERROR" << endl << "Please check your city name." << endl;
    }

    void deletByCoordinate() {
        cout << "Enter city coordinate :" << endl;
        DB tmpx, tmpy;
        City *tmpcity = pointSearchByCoordinate(Point(tmpx, tmpy));
        if (tmpcity != nullptr) deletTmpCity(tmpcity);
        else cout << "DELETE ERROR" << endl << "Please check your city coordinate." << endl;
    }

    void delet() {
        printSecondLevelUi("delete");
        int typ;
        cin >> typ;
        if (typ == 1) deletByName();
        if (typ == 2) deletByCoordinate();
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(2); cout << fixed;
    CityDataBase c;
    for (; ;) {
        c.printFirstLevelUi();
        int ope;
        cin >> ope ;
        if (ope == 1) c.insert();
        if (ope == 2) c.delet();
        // if (ope == 3) c.search();
        if (ope == 4) break;
    }
    return 0;
}

// because of time limit, this program has lots of bugs
// using carefully