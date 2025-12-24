#include <iostream>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertAtBeginning(int id, string name) {
    Node* newNode = new Node();

    if (newNode == NULL) {
        cout << "No: Memory allocation failed.\n";
    }
    else {
        newNode->id = id;
        newNode->name = name;
        newNode->next = head;
        head = newNode;
        cout << "Yes: Node inserted at the beginning successfully.\n";
    }
}

// Insert at End
void insertAtEnd(int id, string name) {
    Node* newNode = new Node();

    if (newNode == NULL) {
        cout << "No: Memory allocation failed.\n";
        return;
    }

    newNode->id = id;
    newNode->name = name;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        cout << "Yes: Node inserted as the first element.\n";
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        cout << "Yes: Node inserted at the end successfully.\n";
    }
}

// Insert at Specific Position
void insertAtPosition(int id, string name, int position) {
    if (position <= 0) {
        cout << "No: Invalid position.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->id = id;
    newNode->name = name;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Yes: Node inserted at position 1 successfully.\n";
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "No: Position out of range.\n";
        delete newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Yes: Node inserted at position " << position << ".\n";
    }
}

// Delete at Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "No: List is empty. Cannot delete.\n";
    }
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Yes: Node deleted from the beginning successfully.\n";
    }
}

// Delete at End
void deleteAtEnd() {
    if (head == NULL) {
        cout << "No: List is empty. Cannot delete.\n";
    }
    else if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Yes: Last node deleted successfully.\n";
    }
    else {
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
        cout << "Yes: Node deleted from the end successfully.\n";
    }
}

// Delete at Specific Position
void deleteAtPosition(int position) {
    if (head == NULL) {
        cout << "No: List is empty.\n";
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Yes: Node deleted from position 1.\n";
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "No: Position out of range.\n";
    }
    else {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "Yes: Node deleted from position " << position << ".\n";
    }
}

// Search by ID
void searchNode(int id) {
    if (head == NULL) {
        cout << "No: List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Yes: Node found -> ID: "
                << temp->id << " , Name: "
                << temp->name << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "No: Node not found.\n";
}

// Traverse Linked List (Show Elements)
void traverse() {
    if (head == NULL) {
        cout << "No: List is empty. No elements to show.\n";
        return;
    }

    Node* temp = head;
    cout << "\nYes: Showing list elements:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id
            << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    int choice, id, pos;
    string name;

    while (true) {
        cout << "\n1.Insert Begin";
        cout << "\n2.Insert End";
        cout << "\n3.Insert Position";
        cout << "\n4.Delete Begin";
        cout << "\n5.Delete End";
        cout << "\n6.Delete Position";
        cout << "\n7.Search";
        cout << "\n8.Show Elements";
        cout << "\n9.Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            insertAtBeginning(id, name);
            break;

        case 2:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            insertAtEnd(id, name);
            break;

        case 3:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Position: ";
            cin >> pos;
            insertAtPosition(id, name, pos);
            break;

        case 4:
            deleteAtBeginning();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            cout << "Enter Position: ";
            cin >> pos;
            deleteAtPosition(pos);
            break;

        case 7:
            cout << "Enter ID to search: ";
            cin >> id;
            searchNode(id);
            break;

        case 8:
            traverse();
            break;

        case 9:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "No: Invalid choice.\n";
        }
    }
}