#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <cstring>
#include <fstream>
#include "Graph.h"
#include "MediaClass.h"

void fileInput(Graph & subway, int i){
    std::string site1, site2;
    double power;
    std::fstream fin;
    char inputFile[50];
    sprintf(inputFile, "/home/liuyang/Code/Shanghai_Subway/Data/Line%d.dat", i);
    std::string filePath(inputFile);
    fin.open(inputFile);
    if (fin.is_open()) {
        fin >> site1;
        subway.addVertex(site1,subway.LINE[i]);
        while (!fin.eof()) {
            fin >> power >> site2;
            subway.addVertex(site2,subway.LINE[i]);
            subway.addEdge(site1,site2,power);
            site1 = site2;
        }
        fin.close();
    } else {
        std::cout << "File Open Failed, File:" << i << std::endl;
    }
}

void fileInput(Graph & subway, const char * inputFile, int i){
    std::string site1, site2;
    double power;
    std::fstream fin;
    std::string filePath(inputFile);
    fin.open(inputFile);
    if (fin.is_open()) {
        fin >> site1;
        subway.addVertex(site1,subway.LINE[i]);
        while (!fin.eof()) {
            fin >> power >> site2;
            subway.addVertex(site2,subway.LINE[i]);
            subway.addEdge(site1,site2,power);
            site1 = site2;
        }
        fin.close();
    } else {
        std::cout << "File Open Failed, File:" << i << std::endl;
    }
}

void buildVertex(Graph & subway) {
    fileInput(subway,1);
    fileInput(subway,2);
    fileInput(subway,3);
    fileInput(subway,4);
    fileInput(subway,5);
    fileInput(subway,6);
    fileInput(subway,7);
    fileInput(subway,8);
    fileInput(subway,9);
    fileInput(subway,10);
    fileInput(subway,11);
    fileInput(subway,12);
    fileInput(subway,13);
    fileInput(subway,16);
    fileInput(subway,"/home/liuyang/Code/Shanghai_Subway/Data/Line10_other.dat",10);
    fileInput(subway,"/home/liuyang/Code/Shanghai_Subway/Data/Line11_other.dat",11);
}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //Register
    qmlRegisterType<MediaClass>("liuyang.Media", 1, 0, "MediaClass");



//    QList<QString> l = c.shortestPath("昌吉东路","同济大学");
//    for(int i = 0; i < l.length(); i++){
//        std::cout << l[i].toUtf8().constData() << std::endl;
//    }



    //
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
