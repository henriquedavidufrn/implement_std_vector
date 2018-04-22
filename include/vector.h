#ifndef SC_VECTOR_H 
#define SC_VECTOR_H // A include guard do STL é _STL_VECTOR_H, no entanto, é legal colocar o nome do namespace mesmo assim para nao confundir.

#include <iostream>

namespace sc {
    
    template < typename T>
    class MyIterator {
        
        public:
            
            MyIterator();
            
//             const Object & operator*( ) const;
            
            /// Incrementar o vetor uma vez.
            MyIterator & operator++( );
            // ++it;
            
            /// Incrementar o vetor uma quantidade x de vezes.
            MyIterator operator++( int );
            // it++;
            
            /// Decrementar o vetor uma única vez.
            MyIterator & operator--( );
            // --it;
            
            /// Decrementar o vetor uma quantidade x de vezes.
            MyIterator operator--( int ); 
            // it--
            
            /// Comparar dois iteradores se são iguais.
            bool operator==( const MyIterator<T> & rhs );
            
            /// Comprar dois iteradores se são difentes.
            bool operator!= ( const MyIterator<T> & rhs );

            /// Obter para qual local o ponteiro está apontando.
            T & getcurrent(){
            	return this->current; 
            }
            
        private:
            
            T *current;
        
    };
    
	template < typename T >
    class vector {
        
        public:
            
            // [-] ALIAS
            
            using size_type = unsigned long;                                //!< The size type.
            using value_type = T;                                           //!< The value_type.
            using pointer = value_type *;                                   //!< Pointer to a value stored in the container. 
            using reference = value_type &;                                 //!< Reference to a value stored in the container. 
            using const_reference = const value_type &;                     //!< Const reference to a value stored in the container.
            using iterator = MyIterator< value_type >;                       //!< The iterator, instantiated from a template class. 
            using const_iterator = MyIterator< const value_type >;           //!< The const_iterator, instantiated from a template class.
            
            // [--] PUBLIC ATTRIBUTES
            
            const static size_type DEFAULT_SIZE = 0;
            
            // [I] SPECIAL MEMBERS

            /// Gera um vetor com a configuração padrão - tamanho 0.
            vector( ); 
            ~vector( );
            vector(const vector&);
            //vector(vector&&);
            
            //template < typename InputItr >
            //vector( InputItr, InputItr );
            vector & operator=( const vector & );
            vector & operator=( vector && );

            // [II] ITERATORS
            
            iterator begin(void);
            iterator end(void);
            //const_iterator cbegi(void) const;
            //const_iterator cend(void) const;
        
            // [III] Capacity

            size_type size( void ) const;
            size_type capacity( void ) const;
            bool empty( void ) const;

            // [IV] Modifiers

            //void clear( void );
            //void push_front( const_reference );
            //void push_back( const_reference );
            //void pop_back( void );
            //void pop_front( void );
            //iterator insert( iterator , const_reference );
            //template < typename InputItr >
            //iterator insert( iterator , InputItr , InputItr );
            //iterator insert( iterator, std::initializer_list< value_type > );
            //void reserve( size_type );
            //void shrink_to_fit( void );
            //void assign( const_reference );
            //void assign( std::initializer_list<T> );
            //template < typename InputItr >
            //void assign( InputItr, InputItr );
            //iterator erase( iterator, iterator );
            //iterator erase( iterator );

            // [V] Element access

            const_reference back( void ) const;
            const_reference front( void ) const;
            const_reference operator[]( size_type ) const;
            reference operator[]( size_type );
            const_reference at( size_type ) const;
            reference at( size_type );
            pointer data( void );
            const_reference data( void ) const;


            // [VI] Operators
            
            bool operator==( const vector & ) const;
            //bool operator!=( const vector & ) const;
            

            // [VII] Friend functions.

            //friend std::ostream & operator<<( std::ostream & os_, const Vector<T> & v_ );
            //friend void swap(vector<T>& first_, vector<T> & second_ );

        private:

            size_type m_end;	//<! Current list size (or index past-last valid element>
            size_type m_capacity;	//<! List’s storage capacity.
            T *m_storage;		//<! Data storage area for the dynamic array.
            
    };
        
}

#endif
