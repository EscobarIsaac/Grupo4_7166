/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: Ejercicio Arbol B
*AUTOR(ES): CHRISTIAN ANDRANGO, ISAAC ESCOBAR, CRISTIAN MARANJE, DANIELA PILATAXI
*FECHA: DOMINGO 09 DE ENERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#pragma once
#include <iostream> 
using namespace std;
template <std::size_t B, typename Type>
class BLinkNode {
public:
	typedef Type data_type;
	data_type* keys_;
		BLinkNode * *childs_ptr_;
	bool is_leaf_;
	std::size_t size_arr_data_;
	BLinkNode() {
		keys_ = new data_type[B];
		childs_ptr_ = new BLinkNode * [B + 1];
		is_leaf_ = false;
		size_arr_data_ = 0;
	}
};
template <std::size_t B, typename Type>
class BLinkTree {
public:
	typedef Type data_type;
	BLinkNode<B, Type>* root_ptr_;
	BLinkTree() {
		root_ptr_ = nullptr;
	}
	~BLinkTree() {}
	bool empty() const { return root_ptr_ == 0; }
	bool search(const data_type& value) const {
		if (empty()) {
			std::cout << "Arbol Vacio " << "\n";
			return false;
		}
		else {
			BLinkNode<B, Type>* pivot = root_ptr_;
			while (!pivot->is_leaf_) {
				for (short i = 0; i < pivot->size_arr_data_; ++i) {
					if (value < pivot->keys_[i]) {
						pivot = pivot->childs_ptr_[i];
						break;
					}
					else if (i + 1 == pivot->size_arr_data_) {
						pivot = pivot->childs_ptr_[i + 1];
						break;
					}
				}
			}
			for (int i = 0; i < pivot->size_arr_data_; ++i)
				if (pivot->keys_[i] == value) {
					return true;
				}
			return false;
		}
	}
	void insert(const data_type& value) {
		if (search(value)) {
			return;
		}
		else if (empty()) {
			root_ptr_ = new BLinkNode<B, Type>;
			root_ptr_->keys_[0] = value;
			root_ptr_->is_leaf_ = true;
			root_ptr_->size_arr_data_ = 1;
			return;
		}
		else {
			BLinkNode<B, Type>* pivot = root_ptr_;
			BLinkNode<B, Type>* parent;
			while (!pivot->is_leaf_) {
				parent = pivot;
				for (int i = 0; i < pivot->size_arr_data_; ++i) {
					if (value < pivot->keys_[i]) {
						pivot = pivot->childs_ptr_[i];
							break;
					}
					else if (i + 1 == pivot->size_arr_data_) {
						pivot = pivot->childs_ptr_[i + 1];
						break;
					}
				}
			}
			if (pivot->size_arr_data_ < B) {
				int i;
				for (i = 0; i < pivot->size_arr_data_; ++i)
					if (pivot->keys_[i] > value)
						break;
				for (short j = pivot->size_arr_data_; j > i; j--)
					pivot->keys_[j] = pivot->keys_[j - 1];
				pivot->keys_[i] = value;
				pivot->size_arr_data_++;
				pivot->childs_ptr_[pivot->size_arr_data_] = pivot->childs_ptr_[pivot -> size_arr_data_ - 1];
				pivot->childs_ptr_[pivot->size_arr_data_ - 1] = nullptr;
				std::cout << "Insertando " << value << "\n";
			}
			else {
				std::cout << "Insertando " << value << "\n";
				std::cout << "Division Realizada" << "\n";
				BLinkNode<B, Type>* new_leaf_ = new BLinkNode<B, Type>;
				new_leaf_->is_leaf_ = true;
				int aux_[B + 1];
				short i;
				for (i = 0; i < B; ++i)
					aux_[i] = pivot->keys_[i];
				for (i = 0; i < B; ++i)
					if (aux_[i] > value)
						break;
				for (short j = B; j > i; j--)
					aux_[j] = aux_[j - 1];
				aux_[i] = value;
				pivot->size_arr_data_ = (B + 1) / 2;
				new_leaf_->size_arr_data_ = B + 1 - (B + 1) / 2;
				for (i = 0; i < pivot->size_arr_data_; ++i)
					pivot->keys_[i] = aux_[i];
				for (i = 0; i < new_leaf_->size_arr_data_; ++i)
					new_leaf_->keys_[i] = aux_[pivot->size_arr_data_ + i];
				pivot->childs_ptr_[pivot->size_arr_data_] = new_leaf_;
				new_leaf_->childs_ptr_[new_leaf_->size_arr_data_] = pivot->childs_ptr_[B];
				pivot->childs_ptr_[B] = nullptr;
				if (pivot == root_ptr_) {
					root_ptr_ = new BLinkNode<B, Type>;
					root_ptr_->keys_[0] = new_leaf_->keys_[0];
					root_ptr_->childs_ptr_[0] = pivot;
					root_ptr_->childs_ptr_[1] = new_leaf_;
					root_ptr_->is_leaf_ = false;
					root_ptr_->size_arr_data_ = 1;
				}
				else
				{
					insertAuxFunction(new_leaf_->keys_[0], parent = nullptr, new_leaf_);
				}
			}
		}
	}
	void remove(const data_type& value) {
		if (empty()) {
			std::cout << "Arbol Vacio" << "\n";
			return;
		}
			if (!search(value)) {
				std::cout << value << " No encontrado " << "\n";
				return;
			}
		int i;
		BLinkNode<B, Type>* pivot = root_ptr_;
		BLinkNode<B, Type>* parent = nullptr;
		int left_ = -1;
		int right_ = -1;
		while (!pivot->is_leaf_) {
			parent = pivot;
			for (i = 0; i < pivot->size_arr_data_; ++i) {
				if (value < pivot->keys_[i]) {
					left_ = i - 1;
					right_ = i + 1;
					pivot = pivot->childs_ptr_[i];
					break;
				}
				else if (i + 1 == pivot->size_arr_data_) {
					left_ = i;
					right_ = i + 2;
					pivot = pivot->childs_ptr_[i + 1];
					break;
				}
			}
		}
		for (i = 0; i < pivot->size_arr_data_; ++i)
			if (pivot->keys_[i] == value)
				break;
		pivot->size_arr_data_--;
		for (; i < pivot->size_arr_data_; ++i)
			pivot->keys_[i] = pivot->keys_[i + 1];
			pivot->childs_ptr_[pivot->size_arr_data_] = pivot->childs_ptr_[pivot -> size_arr_data_ + 1];
		pivot->childs_ptr_[pivot->size_arr_data_ + 1] = nullptr;
		std::cout << "Eliminado , eliminado...!!! " << value << "\n";
		if (pivot->size_arr_data_ < (B + 1) / 2) {
			std::cout << "Underflow" << "\n";
			if (pivot == root_ptr_) {
				if (pivot->size_arr_data_ == 0) {
					BLinkNode<B, Type>* temp = root_ptr_;
					root_ptr_ = nullptr;
					delete(temp);
				}
			}
			if (left_ >= 0) {
				BLinkNode<B, Type>* aux_left_ = parent->childs_ptr_[left_];
				if (aux_left_->size_arr_data_ > (B + 1) / 2) {
					for (i = pivot->size_arr_data_; i > 0; i--)
						pivot->keys_[i] = pivot->keys_[i - 1];
					pivot->childs_ptr_[pivot->size_arr_data_ + 1] = pivot->childs_ptr_[pivot -> size_arr_data_];
					pivot->childs_ptr_[pivot->size_arr_data_] = nullptr;
					pivot->size_arr_data_++;
					aux_left_->size_arr_data_--;
					parent->keys_[left_] = aux_left_->keys_[aux_left_->size_arr_data_];
					pivot->keys_[0] = aux_left_->keys_[aux_left_->size_arr_data_];
					aux_left_->childs_ptr_[aux_left_->size_arr_data_] = aux_left_ -> childs_ptr_[aux_left_->size_arr_data_ + 1];
					aux_left_->childs_ptr_[aux_left_->size_arr_data_ + 1] = nullptr;
					return;
				}
			}
			if (right_ <= parent->size_arr_data_) {
				BLinkNode<B, Type>* aux_right = parent->childs_ptr_[right_];
					if (aux_right->size_arr_data_ > (B + 1) / 2) {
						pivot->childs_ptr_[pivot->size_arr_data_ + 1] = pivot->childs_ptr_[pivot -> size_arr_data_];
						pivot->childs_ptr_[pivot->size_arr_data_] = nullptr;
						pivot->keys_[pivot->size_arr_data_] = aux_right->keys_[0];
						parent->keys_[right_ - 1] = aux_right->keys_[0];
						pivot->size_arr_data_++;
						aux_right->size_arr_data_--;
						for (i = 0; i < aux_right->size_arr_data_; ++i)
							aux_right->keys_[i] = aux_right->keys_[i + 1];
						aux_right->childs_ptr_[aux_right->size_arr_data_] = aux_right -> childs_ptr_[aux_right->size_arr_data_ + 1];
						aux_right->childs_ptr_[aux_right->size_arr_data_ + 1] = nullptr;
						return;
					}
			}
			if (left_ >= 0) {
				BLinkNode<B, Type>* aux_left_ = parent->childs_ptr_[left_];
				if (aux_left_->size_arr_data_ + pivot->size_arr_data_ < B + 1) {
					for (i = 0; i < pivot->size_arr_data_; ++i)
						aux_left_->keys_[aux_left_->size_arr_data_ + i] = pivot->keys_[i];
					aux_left_->childs_ptr_[aux_left_->size_arr_data_] = nullptr;
					aux_left_->size_arr_data_ = aux_left_->size_arr_data_ + pivot -> size_arr_data_;
					aux_left_->childs_ptr_[aux_left_->size_arr_data_] = pivot -> childs_ptr_[pivot->size_arr_data_];
					removeAuxFunction(parent->keys_[left_], parent);
					return;
				}
			}
			if (right_ <= parent->size_arr_data_) {
				BLinkNode<B, Type>* aux_right = parent->childs_ptr_[right_];
				if (pivot->size_arr_data_ + aux_right->size_arr_data_ < B + 1) {
					for (i = 0; i < aux_right->size_arr_data_; ++i)
						pivot->keys_[pivot->size_arr_data_ + i] = aux_right->keys_[i];
					pivot->childs_ptr_[pivot->size_arr_data_] = nullptr;
					pivot->size_arr_data_ = pivot->size_arr_data_ + aux_right->size_arr_data_;
					pivot->childs_ptr_[pivot->size_arr_data_] = aux_right -> childs_ptr_[aux_right->size_arr_data_];
					removeAuxFunction(parent->keys_[right_ - 1], parent);
					return;
				}
			}
		}
		return;
	} BLinkNode<B, Type>* findParent(BLinkNode<B, Type>* pivot, BLinkNode<B,
		Type>* child) {
		if (pivot->is_leaf_ == true)
			return nullptr;
		BLinkNode<B, Type>* parent = nullptr;
		for (int i = 0; i < pivot->size_arr_data_ + 1; ++i) {
			if (pivot->childs_ptr_[i] == child)
				return pivot;
			else {
				parent = findParent(pivot->childs_ptr_[i], child);
				if (parent)
					return parent;
			}
		}
		return nullptr;
	}
	void insertAuxFunction(int value, BLinkNode<B, Type>* pivot, BLinkNode<B,
		Type>* child) {
		if (pivot->size_arr_data_ < B) {
			int i;
			for (i = 0; i < pivot->size_arr_data_; ++i)
				if (pivot->keys_[i] > value)
					break;
			for (int j = pivot->size_arr_data_; j > i; j--) {
				pivot->keys_[j] = pivot->keys_[j - 1];
				pivot->childs_ptr_[j + 1] = pivot->childs_ptr_[j];
			}
			pivot->keys_[i] = value;
			pivot->size_arr_data_++;
			pivot->childs_ptr_[i + 1] = child;
		}
		else {
			std::cout << "Overflow!" << "\n";
			BLinkNode<B, Type>* newleaf = new BLinkNode<B, Type>;
			newleaf->is_leaf_ = false;
			int temp[B + 1];
			short i;
			BLinkNode<B, Type>* temp2[B + 2];
			temp2[B] = pivot->childs_ptr_[B];
			for (i = 0; i < B; ++i) {
				temp[i] = pivot->keys_[i];
				temp2[i] = pivot->childs_ptr_[i];
			}
			for (i = 0; i < B; ++i)
				if (temp[i] > value)
					break;
			for (short j = B; j > i; j--) {
				temp[j] = temp[j - 1];
				temp2[j + 1] = temp2[j];
			}
			temp[i] = value;
			temp2[i + 1] = child;
			pivot->size_arr_data_ = (B + 1) / 2;
			newleaf->size_arr_data_ = B - (B + 1) / 2;
			for (i = 0; i < pivot->size_arr_data_; ++i)
				pivot->keys_[i] = temp[i];
			for (i = 0; i < pivot->size_arr_data_ + 1; ++i)
				pivot->childs_ptr_[i] = temp2[i];
			for (i = 0; i < newleaf->size_arr_data_; ++i)
				newleaf->keys_[i] = temp[pivot->size_arr_data_ + 1 + i];
			for (i = 0; i < newleaf->size_arr_data_ + 1; ++i)
				newleaf->childs_ptr_[i] = temp2[pivot->size_arr_data_ + 1 + i];
			if (pivot == root_ptr_) {
				root_ptr_ = new BLinkNode<B, Type>;
				root_ptr_->keys_[0] = temp[pivot->size_arr_data_];
				root_ptr_->childs_ptr_[0] = pivot;
				root_ptr_->childs_ptr_[1] = newleaf;
				root_ptr_->childs_ptr_[2] = nullptr;
				root_ptr_->is_leaf_ = false;
				root_ptr_->size_arr_data_ = 1;
			}
			else {
				insertAuxFunction(temp[pivot->size_arr_data_], findParent(root_ptr_, pivot),
					newleaf);
			}
		}
	}
	void removeAuxFunction(int value, BLinkNode<B, Type>* pivot) {
		int i;
		for (i = 0; i < pivot->size_arr_data_; ++i)
			if (pivot->keys_[i] == value)
				break;
		pivot->size_arr_data_--;
		BLinkNode<B, Type>* temp = pivot->childs_ptr_[i + 1]; // i++ no funciona xq// :/ 
		for (int j = i; j < pivot->size_arr_data_; j++) {
			pivot->keys_[j] = pivot->keys_[j + 1];
			pivot->childs_ptr_[j + 1] = pivot->childs_ptr_[j + 2];
		}
			delete(temp);
		if (pivot->size_arr_data_ < (B + 1) / 2) {
			std::cout << "Underflow " << "\n";
			if (pivot == root_ptr_) {
				if (pivot->size_arr_data_ == 0) {
					temp = root_ptr_;
					root_ptr_ = pivot->childs_ptr_[0];
					delete(temp);
				}
			}
			else {
				BLinkNode<B, Type>* parent = findParent(root_ptr_, pivot);
				int left_ = -1;
				int right_ = -1;
				for (i = 0; i < parent->size_arr_data_ + 1; ++i) {
					if (pivot == parent->childs_ptr_[i]) {
						left_ = i--;
						right_ = i++;
						break;
					}
					else if (i + 1 == parent->size_arr_data_ + 2) {
						left_ = i;
						right_ = i + 2;
						break;
					}
				}
				if (left_ >= 0) {
					BLinkNode<B, Type>* left_aux = parent->childs_ptr_[left_];
					if (left_aux->size_arr_data_ > (B + 1) / 2) {
						for (i = pivot->size_arr_data_; i > 0; i--)
							pivot->keys_[i] = pivot->keys_[i - 1];
						for (i = pivot->size_arr_data_ + 1; i > 0; ++i)
							pivot->childs_ptr_[i] = pivot->childs_ptr_[i - 1];
							pivot->size_arr_data_++;
						left_aux->size_arr_data_--;
						parent->keys_[left_] = left_aux->keys_[left_aux->size_arr_data_];
						pivot->keys_[0] = left_aux->keys_[left_aux->size_arr_data_];
						pivot->childs_ptr_[0] = left_aux->childs_ptr_[left_aux->size_arr_data_ +
							1];
						left_aux->childs_ptr_[left_aux->size_arr_data_ + 1] = nullptr;
						return;
					}
				}
				if (right_ <= parent->size_arr_data_) {
					BLinkNode<B, Type>* right_aux = parent->childs_ptr_[right_];
					if (right_aux->size_arr_data_ > (B + 1) / 2) {
						pivot->keys_[pivot->size_arr_data_] = parent->keys_[right_ - 1];
						pivot->childs_ptr_[pivot->size_arr_data_ + 1] = right_aux -> childs_ptr_[0];
						parent->keys_[right_ - 1] = right_aux->keys_[0];
						pivot->size_arr_data_++;
						right_aux->size_arr_data_--;
						for (i = 0; i < right_aux->size_arr_data_; ++i)
							right_aux->keys_[i] = right_aux->keys_[i + 1];
						for (i = 0; i < right_aux->size_arr_data_ + 1; ++i)
							right_aux->childs_ptr_[i] = right_aux->childs_ptr_[i + 1];
						right_aux->childs_ptr_[right_aux->size_arr_data_ + 1] = nullptr;
						return;
					}
				}
				if (left_ >= 0) {
					BLinkNode<B, Type>* left_aux = parent->childs_ptr_[left_];
					if (left_aux->size_arr_data_ + pivot->size_arr_data_ < B) {
						left_aux->keys_[left_aux->size_arr_data_] = parent->keys_[left_];
						for (i = 0; i < pivot->size_arr_data_ + 1; ++i)
							left_aux->keys_[left_aux->size_arr_data_ + 1 + i] = pivot->keys_[i];
							for (i = 0; i < pivot->size_arr_data_ + 2; ++i)
								left_aux->childs_ptr_[left_aux->size_arr_data_ + 1 + i] = pivot -> childs_ptr_[i];
						left_aux->size_arr_data_ = left_aux->size_arr_data_ + pivot -> size_arr_data_ + 1;
						removeAuxFunction(parent->keys_[left_], parent);
						return;
					}
				}
				if (right_ <= parent->size_arr_data_) {
					BLinkNode<B, Type>* right_aux = parent->childs_ptr_[right_];
					if (pivot->size_arr_data_ + right_aux->size_arr_data_ < B) {
						pivot->keys_[pivot->size_arr_data_] = parent->keys_[right_ - 1];
						for (i = 0; i < right_aux->size_arr_data_ + 1; ++i)
							pivot->keys_[pivot->size_arr_data_ + 1 + i] = right_aux->keys_[i];
						for (i = 0; i < right_aux->size_arr_data_ + 2; ++i)
							pivot->childs_ptr_[pivot->size_arr_data_ + 1 + i] = right_aux -> childs_ptr_[i];
						pivot->size_arr_data_ = pivot->size_arr_data_ + right_aux -> size_arr_data_ + 1;
						removeAuxFunction(parent->keys_[right_ - 1], parent);
						return;
					}
				}
			}
		}
		return;
	}
	void print(BLinkNode<B, Type>* pivot) {
		if (pivot == nullptr) {
			std::cout << "Arbol Vacio";
			return;
		}
			std::cout << "[ ";
		for (int i = 0; i < pivot->size_arr_data_; ++i)
			std::cout << pivot->keys_[i] << " ";
		if (!pivot->is_leaf_) {
			std::cout << " : < ";
			for (int i = 0; i < pivot->size_arr_data_ + 1; ++i)
				print(pivot->childs_ptr_[i]);
			std::cout << " > ";
		}
		std::cout << " ] ";
	}
};

