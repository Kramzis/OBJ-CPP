#include <iostream>
#include <memory>
#include <fstream>
using namespace std;

class Buffer
{
public:
    Buffer();
    virtual void add(int a) = 0;
    virtual void write() = 0;
    ~Buffer();
};

Buffer::Buffer()
{
    cout << "Konstruktor Buffer" << endl;
}

Buffer::~Buffer()
{
    cout << "Destruktor Buffer" << endl;
}

class BufferArr:public Buffer
{
    int size;
    //int *arr;
    unique_ptr<int[]> arr;
    int nextIndex = 0;
public:
    BufferArr();
    BufferArr(int newSize);
    void add(int a) {
        if (nextIndex < size) {
            arr[nextIndex++] = a;
        } else {
            cout << "Tablica jest pelna, nie mozna dodac elementu" << endl;
        }
    }

    void write() {
        for (int i = 0; i < nextIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

BufferArr::BufferArr()
{

}

BufferArr::BufferArr(int newSize)
{
    this->size=newSize;
    arr = unique_ptr<int[]>(new int[size]);
}

class BufferFile:public Buffer
{
    string fileName;
public:
    BufferFile();
    BufferFile(string newFileName);
    virtual void add(int a) override;
    virtual void write() override;
    ~BufferFile();
};

BufferFile::BufferFile()
{

}

BufferFile::BufferFile(string newFileName)
{
    cout<<"Konstruktor klasy BufferFile"<<endl;
    this->fileName=newFileName;
}

void BufferFile::add(int a)
{
    unique_ptr<ofstream> file(new ofstream);

    file->open(this->fileName, ios::app);
    if(file->is_open())
    {
        *file<<a<<endl;
        file->close();
    }
    else
        cerr<<"Blad przy otwieraniu pliku!"<<endl;
}

void BufferFile::write()
{
    unique_ptr<ifstream> file(new ifstream);
    file->open(this->fileName,ios::in);
    while(!file->eof())
    {
        string line;
        getline(*file,line);
        cout<<line<<endl;
    }
    file->close();
}

BufferFile::~BufferFile()
{
    cout << "Destruktor klasy BufferArr"<<endl;
}

int main() {
    auto ob = BufferFile("numbers.txt");
    cout<<"Plik"<<endl;
    ob.add(11);
    ob.write();
    //auto b = BufferArr(2);
    shared_ptr<Buffer> b(new BufferArr(5));
    cout<<"tablica"<<endl;
    b->add(13);
    b->add(16);
    b->write();
    b->add(15);
}
