return (abs(diff) < 2) ? balanced :
(diff < -1) ? ((thisGetsHeight(t->right->right) > thisGetsHeight(t->right->left)) ? RR : RL) :
(diff > 1)  ? ((thisGetsHeight(t->left->left) > thisGetsHeight(t->left->right)) ? LL : LR) :
throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__));


enum AVL::ebt AVL::getBalanceType(Node *t){
    return ((t == nullptr) || abs(thisGetsHeight(t->left) - thisGetsHeight(t->right)) < 2) ? balanced :
           ((thisGetsHeight(t->left) - thisGetsHeight(t->right)) < -1) ? ((thisGetsHeight(t->right->right) > thisGetsHeight(t->right->left)) ? RR : RL) :
           ((thisGetsHeight(t->left) - thisGetsHeight(t->right)) > 1)  ? ((thisGetsHeight(t->left->left) > thisGetsHeight(t->left->right)) ? LL : LR) :
           throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__));
}

enum AVL::ebt AVL::getBalanceType(Node *t) { return ((t == nullptr) || abs(thisGetsHeight(t->left) - thisGetsHeight(t->right)) < 2) ? balanced : ((thisGetsHeight(t->left) - thisGetsHeight(t->right)) < -1) ? ((thisGetsHeight(t->right->right) > thisGetsHeight(t->right->left)) ? RR : RL) : ((thisGetsHeight(t->left) - thisGetsHeight(t->right)) > 1)  ? ((thisGetsHeight(t->left->left) > thisGetsHeight(t->left->right)) ? LL : LR) : throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__)); }

/* BALANCE FUNCTION */
//we gonna change t, so make sure it's linked!
void AVL::balance(Node *&t){
    switch (((t == nullptr) || abs(thisGetsHeight(t->left) - thisGetsHeight(t->right)) < 2) ? balanced : ((thisGetsHeight(t->left) - thisGetsHeight(t->right)) < -1) ? ((thisGetsHeight(t->right->right) > thisGetsHeight(t->right->left)) ? RR : RL) : ((thisGetsHeight(t->left) - thisGetsHeight(t->right)) > 1)  ? ((thisGetsHeight(t->left->left) > thisGetsHeight(t->left->right)) ? LL : LR) : throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__))) {
        case LR:
            leftRotate(t->left);
        case LL:
            rightRotate(t);
            break;
        case RL:
            rightRotate(t->right);
        case RR:
            leftRotate(t);
        case balanced:
            break;
        default:
            throw std::out_of_range("Incorrect enum balanceType returned on line: " + to_string(__LINE__));
    }
}

enum AVL::ebt AVL::getBalanceType(Node *t){
    if (t == nullptr)
        return balanced;

    int diff = thisGetsHeight(t->left) - thisGetsHeight(t->right); //compare heights of left and right
    if (abs(diff) < 2)
        return balanced;
    else if(diff < -1) {
        //Check if RR or RL imbalance
        return (thisGetsHeight(t->right->right) > thisGetsHeight(t->right->left)) ? RR : RL;
    } else if (diff > 1) {
        //Check if LL or LR imbalance
        return (thisGetsHeight(t->left->left) > thisGetsHeight(t->left->right)) ? LL : LR;
    } else {
        throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__));
    }
}


Node* newRoot2 = t->right;
t->right = newRoot2->left;
newRoot2->left = t;
updateHeight(t);
updateHeight(newRoot2);












/****************************
*   OTHER GUY'S FUNCTIONS   *
****************************/

Node* AVL::balance2(Node* t){
    // pass in just one node and then assign children to variables
    if (t == nullptr)
        return nullptr;
    t->height = updateHeight(t);

    if (getHeight(t->right) - getHeight(t->left) > 1) {
        // RR or RL case
        Node* b = t->right;

        if (getHeight(b->right) - getHeight(b->left) < 0) {
            Node* c = b->left;
            AVL::RL(t, b, c);
            return c;

        } else {
            AVL::RR(t, b);
            return b;
        }

    } else if (a->getBalance() < -1) {
        // LL or LR case
        Node* b = a->left;

        if (b->getBalance() > 0) {
            Node* c = b->right;
            AVL::LR(a, b, c);
            return c;

        } else {
            AVL::LL(a, b);
            return b;
        }

    } else {

        return a;
    }

}
Node* AVL::recRemove(Node*& t, int data){

    if (t->val == data){
        // this has 2 cases

        // if it has just a right child
        if (t->left == nullptr){
            Node* temp = t->right;
            delete t;

            return balance2(temp);
        }

            // if it has just a left child
        else{
            t->left = AVL::IOP(t->left, t);
            //Node* IOP() stuff
            // IOP- this is another recursive method
            // IOP- its function: find IOP, swap values, get rid of IOP
            return balance2(t);
        }

    }

    if (data < t->val){
        ////cout << "\nx < t->data" << endl;
        t->left = recRemove(t->left, data);
        return balance2(t);
    }

    if (data > t->val){
        ////cout << "\nx > t->data" << endl;
        t->right = recRemove(t->right, data);
        return balance2(t);
    }
}

Node* AVL::IOP(Node* t, Node* parent) {
    if (t->right == nullptr){
        // swap between IOP and node to be removed
        int swapData = parent->val;
        parent->val = t->val;
        t->val = swapData;

        // save left child
        Node* savedNode = t->left;

        // delete
        delete t;

        // return left child
        return balance2(savedNode);
    } else {
        ////cout << "curr != NULL" << endl;
        t->right = AVL::IOP(t->right, parent);
        return balance2(t);
    }
}

bool AVL::remove(int data){

    if (AVL::contains(data)) {
        T = AVL::recRemove(T, data);
        return true;
    }
    else return false;
}


bool AVL::recContains(Node* t, int value){

    if (value == t->val)
        return true;
    else if (value < t->val)
        return recContains(t->left, value);
    else if (value > t->val)
        return recContains(t->right, value);
    else return false;
}

bool AVL::contains(int value){
    return (T != nullptr) && AVL::recContains(T, value);
}


int AVL::updateHeight(Node*& t){
    return t->height = (t == nullptr) ? -1 : max(updateHeight(t->left), updateHeight(t->right)) + 1;
}















































#include "AVL.h"
//#include "Node.h"

AVL::~AVL() {
    if (T != nullptr)
        AVL::remove(T->val);
    else delete T;
    T = nullptr;
}

void AVL::rightRotate(Node* &t) {
    if (t == nullptr)
        return;

    Node *newRoot = t->left;
    t->left = newRoot->right;

    //puts our newRoot on top
    newRoot->right = t;
    t = newRoot;
    updateHeight(newRoot->right);
    updateHeight(newRoot);
}

void AVL::leftRotate(Node* &t) {
    if (t == nullptr)
        return;

    Node* newRoot = t->right;
    t->right = newRoot->left;

    //puts our newRoot on top
    newRoot->left = t;
    t = newRoot;
    updateHeight(newRoot->left);
    updateHeight(newRoot);
}

//For inserts, we do the exact same thing as BST, but use our check for balance
//function to see if any silly business happened.

bool AVL::add(int data){
    return insertAVL(T, data);
}

bool AVL::recAdd(Node *&t, int data) {
    // Look ahead and see if CHILDREN are null
    if (t == nullptr) {
        t = new Node(data);
        return true;
    }

        // If there is a node already with the val passed, DON'T add.
    else if (t->val == data)
        return false;

    // If data is less than t->val, go down left. If not, go right.
    //Update heights here. Because of recursion, it will update the height all the way up.
    //call a balance function. Then update height. THEN return returnValue. (NULL will have height of -1)
    bool returnValue = insertAVL(((t->val > data) ? t->left : t->right), data);


    balance(t);
    return returnValue;
}

bool AVL::remove(int data) {
    return eliminate(T, data);
}

bool AVL::recRemove(Node *&t, int data){
    if(t == nullptr)
        return false;
    else if (t->val == data) {
        //if doesn't have a left child...repurpose t to be t = t->right
        if(t->left == nullptr){
            t = t->right;
        } else if (t->right == nullptr) { //no RIGHT child
            t = t->left;
        } else { // 2 children case
            //passing it left so our IOP function doesn't have to.
            int iOPval = getInOrderPredecessor(t->left)->val;

            //Put that in order predecessor at the top!
            t->val = iOPval;
            balance(t);
            return eliminate(t->left, iOPval);
            //bool retVal = eliminate(t->left, iOPval);
            //balance(t);
            //return retVal;
        }
        balance(t);
        return true;
    }
    balance(t);
    return eliminate( ((data < t->val) ? t->left : t->right), data);
    //bool retVal = eliminate( ((data < t->val) ? t->left : t->right), data);
    //balance(t);
    //return retVal;
}

//int AVL::updateHeight(Node* t){
//    //Returns 1 plus whichever height, left or right, is greater.
//    return (t == nullptr) ? -1 : max(t->left, t->right) + 1;
//}

Node* AVL::updateHeight(Node*& t){
    t->height = (t == nullptr) ? -1 : max(updateHeight(t->left), updateHeight(t->right)) + 1;
    return t;
}

//Max of two node heights returned.
int AVL::max(Node* left, Node* right){
    return (getHeight(left) > getHeight(right)) ? getHeight(left) : getHeight(right);
}

/* BALANCE FUNCTION */
//we gonna change t, so make sure it's linked!
void AVL::balance(Node *&t){
    if (t != nullptr)
        updateHeight(t);
    switch (getBalanceType(t)) {
        case LR:
            leftRotate(t->left);
        case LL:
            rightRotate(t);
            break;
        case RL:
            rightRotate(t->right);
        case RR:
            leftRotate(t);
        case balanced:
            break;
        default:
            throw std::out_of_range("Incorrect enum balanceType returned on line: " + to_string(__LINE__));
    }
}

enum AVL::ebt AVL::getBalanceType(Node *t){
    if (t == nullptr)
        return balanced;

    int diff = getHeight(t->left) - getHeight(t->right); //compare heights of left and right
    if (abs(diff) < 2)
        return balanced;
    else if(diff < -1) {
        //Check if RR or RL imbalance
        return (getHeight(t->right->right) > getHeight(t->right->left)) ? RR : RL;
    } else if (diff > 1) {
        //Check if LL or LR imbalance
        return (getHeight(t->left->left) > getHeight(t->left->right)) ? LL : LR;
    } else {
        throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__));
    }
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void AVL::clear() {
    removeMe(T);
    T = nullptr;
}

void AVL::removeMe(Node *&t){
    if(t == nullptr)
        return;

    if (t->left != nullptr)
        removeMe(t->left);
    if (t->right != nullptr)
        removeMe(t->right);

    delete t;
}





void AVL::balance(Node *&t){
    switch (((t == nullptr) || abs(getHeight(t->left) - getHeight(t->right)) < 2) ? balanced : ((getHeight(t->left) - getHeight(t->right)) < -1) ? ((getHeight(t->right->right) >= getHeight(t->right->left)) ? RR : RL) : ((getHeight(t->left) - getHeight(t->right)) > 1)  ? ((getHeight(t->left->left) >= getHeight(t->left->right)) ? LL : LR) : throw std::invalid_argument("What?? How could this be??? Line: " + to_string(__LINE__))) {
        case LR:
            leftRotate(t->left);
        case LL:
            rightRotate(t);
            break;
        case RL:
            rightRotate(t->right);
        case RR:
            leftRotate(t);
        case balanced:
            break;
        default:
            throw std::out_of_range("Incorrect enum balanceType returned on line: " + to_string(__LINE__));
    }
}











