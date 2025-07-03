#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;


// Abstract class
class DocumentElement{
        public:
               virtual string  render()=0;
};

class TextElement:public DocumentElement{
        private:
                string text;
        public:
                TextElement(string t):text(t){}
                string render() override{
                        return text;
                }
};

class ImageElement:public DocumentElement{
        private:
                string path;
        public:
                ImageElement(string p):path(p){}
                string render() override{
                        return "[Image: " + path + "]";
                }
};

class NewLineElement:public DocumentElement{
        public:
                string render() override{
                        return "\n";
                }
};

class TabSpaceElement : public DocumentElement {
        public:
        string render() override {
                return "\t";
        }
};

// Concrete class - holds document elements
class Document{
        public:
                vector<DocumentElement*> elements; //Document elements -text, image, new line,tab
                void addElement(DocumentElement* element){
                        elements.push_back(element);
                }

                string  renderDocument(){
                        string result;
                        for(DocumentElement* element:elements){
                                result+=element->render(); // render of DocumentElement called -either TextElement or ImageElement,etc
                        }
                        return result;
                } 
};

// Abstract class
class Persistence{
        public:
                virtual void save(string data)=0;
};

class FilePersistence:public Persistence{
        public:
                void save(string data) override{
                       ofstream file("document.txt");
                       if(file.is_open()){
                               file<<data;
                               file.close();
                               cout<<"Document saved to document.txt"<<endl;
                       }else{
                               throw "Error: Unable to open file for writing";
                       }
                }
};

class DBPersistence:public Persistence{
        public:
                void save(string data) override{
                      // save to database
                      cout <<"Document saved to database"<<endl;
                }
};

// Main class
class DocumentEditor{
        private:
                Document* doc;
                Persistence* p;
                string renderDocument;// to store the rendered document

        public:
                DocumentEditor(Document* doc,Persistence* p):doc(doc),p(p){}
                      
                void addText(string text){
                        doc->addElement(new TextElement(text));
                }
                void addImage(string path){
                        doc->addElement(new ImageElement(path));
                }
                void addNewLine(){
                        doc->addElement(new NewLineElement());
                }
                void addTabSpace(){
                        doc->addElement(new TabSpaceElement());
                }
                string renderingDocument(){
                        if(renderDocument.empty()){
                                renderDocument=doc->renderDocument();
                        }
                        return renderDocument;
                        
                }
                void saveDocument(){
                        p->save(renderingDocument());
                }
};


int main(){

        Document* document = new Document();
        Persistence* p = new FilePersistence();
        // Persistence* p2 = new DBPersistence();

        DocumentEditor* editor = new DocumentEditor(document,p);

         // Simulate a client using the editor with common text formatting features.
        editor->addText("Hello, world!");
        editor->addNewLine();
        editor->addText("This is a real-world document editor example.");
        editor->addNewLine();
        editor->addTabSpace();
        editor->addText("Indented text after a tab space.");
        editor->addNewLine();
        editor->addImage("picture.jpg");

        // Render and display the final document.
        cout << editor->renderingDocument() << endl;

        editor->saveDocument();


        return 0;
}