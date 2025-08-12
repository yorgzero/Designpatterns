/* GUIFactory example */

class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() { }
};

class WinButton : public Button {
public:
    void paint() {
        std::cout << "I'm a WinButton";
}
};

class OSXButton : public Button  {
public:
    void paint() {
        std::cout << "I am an OSXButton"


class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual ~GUIFactory() { }
};

class WinFactory : public GUIFactory {
public:
    Button* createButton() {
        return new WinButton();
    }
    ~WinFactory() { }
};

class OSXFactory : public GUIFactory {
public:
    Button* createButton() {
        return new OSXButton();
    }

  ~OSXFactory() { }
};

class Application {
public:
    Application(GUIFactory* factory) {
        Button*  button = factory->createButton();
        button->paint();
        delete button;
        delete factory;
    }
};

GUIFactory* createOsSpecificFactory() {
    int sys;
    std::cout << "Enter OS type (0: Windows, 1: MacOS X): ";
    std::cin >> sys;

    if (sys == 0) {
        return new WinFactory();
    } else {
        return new OSXFactory();
    }

int main() {
    Application application(createOsSpecificFactory());

    return 0;

}

