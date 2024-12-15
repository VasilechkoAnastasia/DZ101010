#include <iostream>
#include <string>
using namespace std;

class PC {
protected:
    string name;
    string CPU;
    string GPU;
    string SSD;
    string RAM;
    double price;
public:
    PC(string name, string CPU, string GPU, string SSD, string RAM, double price)
        : name(name), CPU(CPU), GPU(GPU), SSD(SSD), RAM(RAM), price(price) {}

    double GetPrice() const {
        return price;
    }

    virtual void Print() const {
        cout << "Name: " << name << "\n"
            << "CPU: " << CPU << "\n"
            << "GPU: " << GPU << "\n"
            << "SSD: " << SSD << "\n"
            << "RAM: " << RAM << "\n"
            << "Price: " << price << " USD\n";
    }

    virtual ~PC() {}
};

class OfficePC : public PC {
private:
    string microphone;
public:
    OfficePC(string name, string CPU, string GPU, string SSD, string RAM, double price, string microphone)
        : PC(name, CPU, GPU, SSD, RAM, price), microphone(microphone) {}

    void Print() const override {
        cout << "Office PC:\n";
        PC::Print();
        cout << "Microphone: " << microphone << "\n";
    }
};

class GamePC : public PC {
private:
    string keyboard;
    string headphones;

public:
    GamePC(string name, string CPU, string GPU, string SSD, string RAM, double price, string keyboard, string headphones)
        : PC(name, CPU, GPU, SSD, RAM, price), keyboard(keyboard), headphones(headphones) {}

    void Print() const override {
        cout << "Gaming PC:\n";
        PC::Print();
        cout << "Keyboard: " << keyboard << "\n"
            << "Headphones: " << headphones << "\n";
    }
};

class HomePC : public PC {
private:
    string webcamera;
public:
    HomePC(string name, string CPU, string GPU, string SSD, string RAM, double price, string webcamera)
        : PC(name, CPU, GPU, SSD, RAM, price), webcamera(webcamera) {}

    void Print() const override {
        cout << "Home PC:\n";
        PC::Print();
        cout << "Webcamera: " << webcamera << "\n";
    }
};

int main() {
    OfficePC officePC("Office PC", "Intel i5", "Integrated", "256GB", "8GB", 500, "Logitech USB Mic");
    GamePC gamePC("Gaming PC", "Intel i9", "NVIDIA RTX 3080", "1TB", "32GB", 2000, "Varmillo Keyboard", "Razer Headphones");
    HomePC homePC("Home PC", "Intel i3", "Integrated", "512GB", "16GB", 800, "Logitech HD Webcam");

    cout << "Select the type of PC to display its specifications:\n";
    cout << "1. Office PC\n"
         << "2. Gaming PC\n"
         << "3. Home PC\n"
         << "Your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        officePC.Print();
    } else if (choice == 2) {
        gamePC.Print();
    } else if (choice == 3) {
        homePC.Print();
    } else {
        cout << "Invalid input!\n";
    }
}