int main() {
    itemSearch itemsearch;
    itemsearch.readInputFile();
    itemsearch.writeOutputFile();

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Print item frequency list\n";
        cout << "3. Print item frequency histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            itemsearch.searchItem();
            break;
        case 2:
            itemsearch.printList();
            break;
        case 3:
            itemsearch.printHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
