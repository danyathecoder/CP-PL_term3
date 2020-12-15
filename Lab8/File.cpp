//
// Created by danilapoddubny on 15/12/2020.
//


#include "File.h"
#include "Drug.h"

File::File(): name("-"), key(no),size(0){}
File::File(string n, Key k): name(n), key(k), size(0){}
File& operator<<(File& file, const char* s)
{

    if (!file.file.is_open())
    {
        throw 1;
    }

    /*catch (int i)
    {
        Exception ex(i);
        ex.Print();
    }*/
    string str = s;
    file.file << str;
    return file;
}
fstream& operator<<(fstream& out, Drug& drug) {

    if (!out.is_open())
    {
        throw 1;
    }

    /*catch (int i)
    {
        Exception ex(i);
        ex.Print();
    }*/
    int a = out.tellg();
    string name = drug.getName();
    size_t len1 = name.length() + 1;

    string country = drug.getCountry();
    size_t len2 = country.length() + 1;

    int date = drug.getDate();
    int rating = drug.getRating();
    int sold = drug.getSold();

    out.write((char*)(&len1), sizeof(len1));
    out.write((char*)(name.c_str()), len1);

    out.write((char*)(&len2), sizeof(len2));
    out.write((char*)(country.c_str()), len2);

    out.write((char*)(&date), sizeof(date));

    out.write((char*)(&rating), sizeof(rating));

    out.write((char*)(&sold), sizeof(sold));

    return out;
}
File& operator<<(File& file, Drug& drug)
{
    int pos = 0, a = 0, size = 0;

    if (!file.file.is_open())
    {
        cout << "1";
    }

    /*catch (int i)
    {
        Exception ex(i);
        ex.Print();
    }*/
    if (file.key == txt) {
        file.file << drug.getName() << " " << drug.getCountry() << " " << drug.getDate() << " "
                  << drug.getRating() << " " << drug.getSold() << endl;
    }
    else if (file.key == bin) {
        string name = drug.getName();
        size_t len1 = name.length() + 1;

        string country = drug.getCountry();
        size_t len2 = country.length() + 1;

        int date = drug.getDate();
        int rating = drug.getRating();
        int sold = drug.getSold();

        file.file.write((char*)(&len1), sizeof(len1));
        file.file.write((char*)(name.c_str()), len1);

        file.file.write((char*)(&len2), sizeof(len2));
        file.file.write((char*)(country.c_str()), len2);

        file.file.write((char*)(&date), sizeof(date));

        file.file.write((char*)(&rating), sizeof(rating));

        file.file.write((char*)(&sold), sizeof(sold));
    }
    return file;
}
ostream& operator<<(ostream& out, File& file)
{
    int a = 0;

    if (!file.file.is_open())
    {
        throw 1;
    }

    /*catch (int i)
    {
        Exception ex(i);
        ex.Print();
    }*/
    if (file.key == txt) {
        string str;
        while (!file.file.eof()) {
            getline(file.file, str);
            a = file.file.tellg();
            cout << str << endl;
        }
    }
    else if (file.key == bin) {
        int i = 0;
        int size = 0, step = 0;
        while (i < file.size) {
            int date;
            int rating;
            int sold;

            size_t len;

            file.file.read((char*)(&len), sizeof(len));
            char* f = new char[len];

            file.file.read((char*)(f), len);
            f[len - 1] = '\0';

            file.file.read((char*)(&len), sizeof(len));
            char* s = new char[len];

            file.file.read((char*)(s), len);
            s[len - 1] = '\0';

            file.file.read((char*)(&date), sizeof(int));
            file.file.read((char*)(&rating), sizeof(int));

            file.file.read((char*)(&sold), sizeof(int));

            cout << f << " " << s << " " << date << " " << rating << " " << sold << endl;

            delete[] f;
            delete[] s;
            i++;

        }
    }
    return out;
}

File::~File() { file.close(); }
void File::open(string mode)
{
    switch (key)
    {
        case txt: {
            if (mode == "r") {
                file.open(name, ios_base::in);
            }
            else if (mode == "add") {
                file.open(name, ios_base::app);
            }
            else if (mode == "w") {
                file.open(name, ios_base::out);
            }
            else if (mode == "wr") {
                file.open(name, ios_base::in | ios_base::out);
            }
            break;
        }
        case bin: {
            if (mode == "r") {
                file.open(name, ios_base::binary | ios_base::in);
            }
            else if (mode == "add") {
                file.open(name, ios_base::binary | ios_base::app);
            }
            else if (mode == "w") {
                file.open(name, ios_base::binary | ios_base::out);
            }
            else if (mode == "wr") {
                file.open(name, ios_base::binary | ios_base::in | ios_base::out);
            }
            break;
        }

    }
    /*if (!file.is_open())
    {
        throw ;
    }
    */
}
void File::close()
{
    file.close();
}
void File::begin()
{
    file.seekg(0, ios_base::beg);
}
void File::set_size(int s) {
    size = s;
}
int File::get_size() {
    return	size;
}
Drug File::read()
{
    string str;
    Drug drug;
    getline(this->file, str, ' ');
    drug.setName(str);
    getline(this->file, str, ' ');
    drug.setCountry(str);
    getline(this->file, str, ' ');
    drug.setDate(stoi(str));
    getline(this->file, str, ' ');
    drug.setRating(stoi(str));
    getline(this->file, str);
    drug.setSold(stoi(str));
    return drug;
}
void File::edit(int line, Drug mas[]) {
    this->open("wr");

    int a, b;

    /*try {
        if (!file.is_open())
        {
            throw 1;
        }
    }
    catch (int i)
    {
        Exception ex(i);
        ex.Print();
        return;
    }*/
    Drug tmp;
    if (this->key == txt) {
        string str;
        for (int i = 0; i < line - 1; i++)
            getline(this->file, str);
        getline(this->file, str, ' ');
        tmp.setName(str);
        getline(this->file, str, ' ');
        tmp.setCountry(str);
        getline(this->file, str, ' ');
        tmp.setDate(stoi(str));
        getline(this->file, str, ' ');
        tmp.setRating(stoi(str));
        getline(this->file, str);
        tmp.setSold(stoi(str));
    }
    else if (this->key == bin) {
        size_t len;
        for (int i = 0; i < line; i++) {

            this->file.read((char*)(&len), sizeof(len));
            char* n = new char[len];
            string name;
            string country;
            int rating = 0, date = 0, sold = 0;

            this->file.read((char*)(n), len);
            name = n;
            name[len - 1] = '\0';

            this->file.read((char*)(&len), sizeof(len));
            this->file.read((char*)(n), len);
            country = n;
            country[len - 1] = '\0';

            this->file.read((char*)(&date), sizeof(int));
            this->file.read((char*)(&rating), sizeof(int));
            this->file.read((char*)(&sold), sizeof(int));

            tmp.setName(name);
            tmp.setCountry(country);
            tmp.setDate(date);
            tmp.setRating(rating);
            tmp.setSold(sold);
            delete[]n;
        }
        a = file.tellg();
    }

    cout << "What do you want to change?\n1 - name\n2 - number of groups\n3 - number of labs per subject\n4 - subject\n5 - number of current labs" << endl;
    int choice;
    cin >> choice;
    cout << "Put new data: ";
    switch (choice) {
        case 1: {
            string a;
            rewind(stdin);
            cin >> a;
            tmp.setName(a);
            break;
        }
        case 2: {
            string a;
            rewind(stdin);
            cin >> a;
            tmp.setCountry(a);
            break;
        }
        case 3: {
            int a;
            cin >> a;
            tmp.setDate(a);
            break;
        }
        case 4: {
            int a;
            cin >> a;
            tmp.setRating(a);
            break;
        }
        case 5: {
            int a;
            cin >> a;
            tmp.setSold(a);
            break;
        }
    }
    a = file.tellg();
    file.seekg(0, ios_base::end);
    b = file.tellg();
    this->file.seekg(0, ios_base::beg);
    if (this->key == txt) {
        string tmp;
        for (int i = 0; i < line - 1; i++)
            getline(this->file, tmp);
        int pos = this->file.tellg();
        this->file.seekg(pos, ios_base::beg);
        this->file << tmp;
        return;
    }
    else if (this->key == bin) {
        for (int i = 0; i < line - 1; i++)
        {
            size_t len;
            this->file.read((char*)(&len), sizeof(len));
            char* n = new char[len];

            string name;
            string country;
            int rating = 0, date = 0, sold = 0;
            this->file.read((char*)(n), len);
            name = n;
            name[len - 1] = '\0';
            this->file.read((char*)(&date), sizeof(int));
            this->file.read((char*)(&rating), sizeof(int));
            this->file.read((char*)(&len), sizeof(len));
            this->file.read((char*)(n), len);

            this->file.read((char*)(&sold), sizeof(int));

            delete[] n;
        }
        int pos = this->file.tellg();

        char* last = new char[b - a];
        this->file.read((char*)last, b - a);

        this->close();
        this->open("w");
        pos = this->file.tellg();

        for (int i = 0; i < get_size(); i++) {
            if (i != line - 1)
                file << mas[i];
            else {
                file << tmp;
                mas[i].setName(tmp.getName());
                mas[i].setCountry(tmp.getCountry());
                mas[i].setDate(tmp.getDate());
                mas[i].setRating(tmp.getRating());
                mas[i].setSold(tmp.getSold());
            }
        }
    }

    this->close();
}

void File::sortByName()
{
    string tmp;
    string s1, s2;
    int pos;
    this->open("wr");
    /*try {
        if (!file.is_open())
        {
            throw 1;
        }
    }
    catch (int i)
    {
        Exception ex(i);
        ex.Print();
        return;
    }*/
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++)
        {
            this->file.seekg(0, ios_base::beg);
            for (int k = 0; k < j; k++)
                getline(this->file, s1);
            getline(this->file, s1, ' ');
            getline(this->file, s2);
            getline(this->file, s2, ' ');
            if (s1 > s2)
            {
                this->file.seekg(0, ios_base::beg);
                pos = this->file.tellg();
                for (int k = 0; k <= j; k++)
                {
                    getline(this->file, s1);
                    pos = this->file.tellg();
                }
                tmp = s1;
                getline(this->file, s2);
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                {
                    getline(this->file, s1);
                }
                pos = this->file.tellg();
                this->file.seekg(pos, ios_base::beg);
                this->file << s2 << '\n';
                this->file << tmp << '\n';
            }
        }
    }
    this->close();
}
void File::sortByDate() {
    string tmp;
    string s1, s2;
    int i1, i2;
    int pos;
    this->open("wr");
    /*try {
        if (!file.is_open())
        {
            throw 1;
        }
    }
    catch (int i)
    {
        Exception ex(i);
        ex.Print();
        return;
    }*/
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++)
        {
            this->file.seekg(0, ios_base::beg);
            for (int k = 0; k < j; k++)
                getline(this->file, s1);
            for(int t=0;t<2;t++)
                getline(this->file, s1, ' ');
            getline(this->file, s2);
            for (int t = 0; t < 2; t++)
                getline(this->file, s2, ' ');
            i1 = stoi(s1);
            i2 = stoi(s2);
            if (i1 > i2)
            {
                this->file.seekg(0, ios_base::beg);
                pos = this->file.tellg();
                for (int k = 0; k <= j; k++) {
                    getline(this->file, s1);
                    pos = this->file.tellg();
                }
                tmp = s1;
                getline(this->file, s2);
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++) {
                    getline(this->file, s1);
                }
                pos = this->file.tellg();
                this->file.seekg(pos, ios_base::beg);
                this->file << s2 << '\n';
                this->file << tmp << '\n';
            }
        }
    }
    this->close();
}
void File::sortByRating() {
    string tmp;
    string s1, s2;
    int i1, i2;
    int pos;
    this->open("wr");
    /*try {
        if (!file.is_open())
        {
            throw 1;
        }
    }
    catch (int i)
    {
        Exception ex(i);
        ex.Print();
        return;
    }*/
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++) {
            this->file.seekg(0, ios_base::beg);
            for (int k = 0; k < j; k++) {
                getline(this->file, s1);
            }
            for (int t = 0; t < 3; t++)
                getline(this->file, s1, ' ');
            getline(this->file, s2);
            for (int t = 0; t < 3; t++)
                getline(this->file, s2, ' ');
            i1 = stoi(s1);
            i2 = stoi(s2);
            if (i1 > i2) {
                this->file.seekg(0, ios_base::beg);
                pos = this->file.tellg();
                for (int k = 0; k <= j; k++) {
                    getline(this->file, s1);
                    pos = this->file.tellg();
                }
                tmp = s1;
                getline(this->file, s2);
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++) {
                    getline(this->file, s1);
                }
                pos = this->file.tellg();
                this->file.seekg(pos, ios_base::beg);
                this->file << s2 << '\n';
                this->file << tmp << '\n';
            }
        }
    }
    this->close();
}
void File::sortByCountry()
{
    string tmp;
    string s1, s2;
    int pos;
    this->open("wr");
    /*try {
        if (!file.is_open())
        {
            throw 1;
        }
    }
    catch (int i)
    {
        Exception ex(i);
        ex.Print();
        return;
    }*/
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++)
        {
            this->file.seekg(0, ios_base::beg);
            for (int k = 0; k < j; k++)
                getline(this->file, s1);
            for (int t = 0; t < 4; t++)
                getline(this->file, s1, ' ');
            getline(this->file, s2);
            for (int t = 0; t < 4; t++)
                getline(this->file, s2, ' ');
            if (s1 > s2)
            {
                this->file.seekg(0, ios_base::beg);
                pos = this->file.tellg();
                for (int k = 0; k <= j; k++)
                {
                    getline(this->file, s1);
                    pos = this->file.tellg();
                }
                tmp = s1;
                getline(this->file, s2);
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                {
                    getline(this->file, s1);
                }
                pos = this->file.tellg();
                this->file.seekg(pos, ios_base::beg);
                this->file << s2 << '\n';
                this->file << tmp << '\n';
            }
        }
    }
    this->close();
}
void File::sortBySold() {
    string tmp;
    string s1, s2;
    int i1, i2;
    int pos;
    this->open("wr");
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++) {
            this->file.seekg(0, ios_base::beg);
            for (int k = 0; k < j; k++) {
                getline(this->file, s1);
            }
            for (int t = 0; t < 4; t++)
                getline(this->file, s1, ' ');
            getline(this->file, s1);
            //getline(this->file, s2);
            for (int t = 0; t < 4; t++)
                getline(this->file, s2, ' ');
            getline(this->file, s2);
            i1 = stoi(s1);
            i2 = stoi(s2);
            if (i1 > i2) {
                this->file.seekg(0, ios_base::beg);
                pos = this->file.tellg();
                for (int k = 0; k <= j; k++) {
                    getline(this->file, s1);
                    pos = this->file.tellg();
                }
                tmp = s1;
                getline(this->file, s2);
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++) {
                    getline(this->file, s1);
                }
                pos = this->file.tellg();
                this->file.seekg(pos, ios_base::beg);
                this->file << s2 << '\n';
                this->file << tmp << '\n';
            }
        }
    }
    this->close();
}