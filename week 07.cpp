#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class CStudent {
    string name;
    string id;
    string mbti;
public:
    CStudent() { cout << "생성자 실행" << endl; } // Q1. 생성자 실행 횟수: 1번
    CStudent(string _name, string _id, string _mbti) : name(_name), id(_id), mbti(_mbti) { cout << "생성자 실행" << endl; }
    CStudent(const CStudent& C) {    //복사 생성자
        this->name = C.name;
        this->id = C.id;
        this->mbti = C.mbti;
        cout << "복사 생성자 실행" << endl;    //Q2. 복사 생성자 실행 횟수: 1번
    }
    ~CStudent() { cout << "소멸자 실행" << endl; }  //Q1. 소멸자 생성자 실행 횟수: 2번
    void set_students(string name, string id, string mbti) {
        this->name = name;
        this->id = id;
        this->mbti = mbti;
    }
    string get_name() { return name; }
    string get_id() { return id; }
    string get_mbti() { return mbti; }
};

class ReadMBTIData {
public:
    ReadMBTIData() {}
    void read_data(string file_path) {
        ifstream input_file(file_path);
        if (!input_file.is_open()) {
            cerr << "Failed to open input file" << endl;
            return;
        }

        int num_rows = 0;
        string line;
        while (getline(input_file, line)) {
            num_rows++;
        }
        input_file.clear();
        input_file.seekg(0, ios::beg);

        name_ = new string[num_rows];
        id_ = new string[num_rows];
        mbti_ = new string[num_rows];

        int i = 0;
        while (getline(input_file, line)) {
            stringstream ss(line);
            string cell;
            int j = 0;
            while (getline(ss, cell, ',')) {
                if (j == 0) {
                    name_[i] = cell;
                }
                else if (j == 1) {
                    id_[i] = cell;
                }
                else if (j == 2) {
                    mbti_[i] = cell;
                }
                j++;
            }
            i++;
        }
        input_file.close();
        num_rows_ = num_rows;
    }

    void print_data() {
        for (int i = 0; i < num_rows_; i++) {
            cout << name_[i] << " " << id_[i] << " " << mbti_[i] << endl;
        }
    }

    int get_num_of_students() {
        return num_rows_;
    }
    CStudent* set_data(CStudent* _OStudent) {
        for (int i = 0; i < num_rows_; ++i) {
            _OStudent[i].set_students(name_[i], id_[i], mbti_[i]);
        }
        return _OStudent;
    }
    ~ReadMBTIData() {
        delete[] name_;
        delete[] id_;
        delete[] mbti_;
    }
private:
    string* name_;
    string* id_;
    string* mbti_;
    int num_rows_;
};

//Q6.func2개 구현 (오버로딩)
//int func(int a, int b) {
    //if (a > b) {
        //return a;
    //}
    //else if (a < b) {
        //return b;
    //}
//}
//Q8. ::클래스에 있는 변수다라고 범위 지정 / 객체 만들기 전에 프로그램을 만들기로 함
//Q9. static이 만들어지기 전부터 있는 객체 this이기 때문에 당연히 사용불가
//Q10. 클래스 이용에 사용되는 연산자는 불가능

//Q5.
CStudent func_changeMBTI(CStudent C) {
    string _mbti = "ISTP";
    C.set_students(C.get_name(), C.get_id(), _mbti);
    return C;
}

int main() {
    //Q5. 복사 생성자 실행 횟수: 3번  소멸자 실행 횟수: 4번
    //CStudent Sugeong("sugeong", "2023", "ISTJ");
    //CStudent Sungshin = Sugeong;
    //Sugeong = func_changeMBTI(Sugeong);
    //cout << Sugeong.get_mbti() << endl;
    //return 0;

    //Q6.
    //int array[5] = { 1, 9, -1, 5, 4 };
    // 2와 3 중 큰 수 반환
    //cout << func(2, 3) << endl; // 2와 3 중 큰 수 반환
    // 배열 array, array의 크기 5를 이용해 배열에서 가장 큰 수 반환
    //cout << func(array, 5) << endl;
    //return 0;

    ReadMBTIData data;
    data.read_data("C:\\Users\\sungshin\\Downloads\\2023_Students.csv");
    ReadMBTIData copy_data(data);
    //data.print_data();

    //CStudent Sugeong("sugeong", "2023", "ISTJ");
    //func_changeMBTI(Sugeong);
    //int num_of_students;
    //num_of_students = data.get_num_of_students();

    //CStudent* OStudent = new CStudent[num_of_students];
    //data.set_data(OStudent);

    //string mbti_table[16] = { "ISTJ", "ISTP", "INFJ", "INTJ", "ISFJ", "ISFP", "INFP", "INTP", "ESTJ", "ESFP", "ENFP", "ENTP", "ESFJ", "ESTP", "ENFJ", "ENTJ" };
    //int idx_table[16];
    //for (int i = 0; i < 16; ++i) {
        //idx_table[i] = 0;
        //for (int j = 0; j < num_of_students; ++j) {
            //if (mbti_table[i].compare(OStudent[j].get_mbti()) == 0) {
                //idx_table[i]++;
            //}
        //}
    //}
    //for (int i = 0; i < 16; ++i) {
        //cout << mbti_table[i] << " : " << idx_table[i] << endl;
    //}

    //delete[] OStudent;
    return 0;

}