/*
 * Copyright (c) 1997, 2013, Oracle and/or its affiliates. All rights reserved.
 * ORACLE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
package ehu.eda.list.linkedImp;

import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * Una implementaciÃ³n de listas, usando una lista de doble enlace
 * (double-linked-list).
 * 
 * En esta implementaciÃ³n, las listas tienen capacidad limitada solo por la
 * memoria disponible.
 * 
 * Todas las operaciones tienen tiempo de ejecucion en O(1) (tiempo constante:
 * independiente de la entrada y del tamaÃ±o de la lista).
 *
 * Esta es una clase "genÃ©rica".
 * 
 * El cÃ³digo estÃ¡ tomado de la clase LinkedList de a librerÃ­a estÃ¡ndar, escrito
 * por Josh Bloch.
 * 
 */
public class IterableDoubleLinkedList<E> {
	/*
	 * E: tipo de elementos almacenados en la lista (parÃ¡metro de la clase genÃ©rica)
	 */

	/*
	 * first es el primer nodo de la lista, last es el Ãºltimo nodo de la lista.
	 * 
	 * lista vacÃ­a <=> first es null y last es null
	 */
	private Node<E> first; // el primer nodo de la lista
	private Node<E> last; // el Ãºltimo nodo de la lista

	int size = 0; // nÃºmero de elementos en la lista

	public boolean isEmpty() {
		return first == null;
	}

	public int size() {
		return size;
	}

	public void addFirst(E e) {
		linkFirst(e);
	}

	public void addLast(E e) {
		linkLast(e);
	}

	public E getFirst() {
		if (first == null) {
			throw new NoSuchElementException();
		}
		return first.item;
	}

	public E getLast() {
		if (last == null) {
			throw new NoSuchElementException();
		}
		return last.item;
	}

	//TODO	
	public E get(int index) {
		Node<E> indexNode = first;
		int i=0;
		//assert index<size
		while (i<index) {
			indexNode=indexNode.next;
			i++;
		}
		return indexNode.item;
	}
	
	public E set(int index, E element) {
		Node<E> indexNode = first;
		int i=0;
		//assert index<size
		while (i<=index) {
			indexNode=indexNode.next;
			i++;
		}
		E tmp=indexNode.item;
		indexNode.item=element;
		return tmp;
	}
	
	public void add(int index, E element) {
		if(index==0) {
			addFirst(element);
		}else if(index==size){
			addLast(element);
		}else {
		Node<E> indexNode = first;
		int i=0;
		while (i<index) {
			indexNode=indexNode.next;
			i++;
		}
		final Node<E> newNode = new Node<>(indexNode, element, indexNode.next);
		indexNode.next=newNode;
		newNode.next.prev=newNode;
		size++;
		}
	}
	
	public E remove(int index) {
		if(index==0) {
			return removeFirst();
		}else if(index==size-1){
			return removeLast();
		}else {
		Node<E> indexNode = first;
		int i=0;
		while (i<index) {
			indexNode=indexNode.next;
			i++;
		}
		indexNode.prev.next=indexNode.next;
		indexNode.next.prev=indexNode.prev;
		indexNode.prev=null;
		indexNode.next=null;
		size--;
		return indexNode.item;
		}
	}
	
	public E removeFirst() {
		final Node<E> f = first;
		if (f == null) {
			throw new NoSuchElementException();
		}
		return unlinkFirst(f);
	}

	public E removeLast() {
		final Node<E> l = last;
		if (l == null) {
			throw new NoSuchElementException();
		}
		return unlinkLast(l);
	}

	/**
	 * Returns a list-iterator of the elements in this list (in proper sequence),
	 * starting at the first position in the list.
	 */
	public ListIterator<E> listIterator() {
		return new ListItr();
	}

	/*
	 * HASTA AQUÃ� LA PARTE PÃšBLICA. A CONTINUACIÃ“N LA PARTE PRIVADA.
	 */

	/**
	 * Links e as last element.
	 */
	private void linkLast(E e) {
		final Node<E> l = last;
		final Node<E> newNode = new Node<>(l, e, null);
		last = newNode;
		if (l == null) {
			first = newNode;
		} else {
			l.next = newNode;
		}
		size++;
	}

	/**
	 * Links e as first element.
	 */
	private void linkFirst(E e) {
		final Node<E> f = first;
		final Node<E> newNode = new Node<>(null, e, f);
		first = newNode;
		if (f == null) {
			last = newNode;
		} else {
			f.prev = newNode;
		}
		size++;
	}

	private E unlinkFirst(Node<E> f) {
		// assert f == first && f != null;
		final E element = f.item;
		final Node<E> next = f.next;
		f.item = null;
		f.next = null; // help GC
		first = next;
		if (next == null) {
			last = null;
		} else {
			next.prev = null;
		}
		size--;
		return element;
	}

	/**
	 * Unlinks non-null last node l.
	 */
	private E unlinkLast(Node<E> l) {
		// assert l == last && l != null;
		final E element = l.item;
		final Node<E> prev = l.prev;
		l.item = null;
		l.prev = null; // help GC
		last = prev;
		if (prev == null) {
			first = null;
		} else {
			prev.next = null;
		}
		size--;
		return element;
	}

	/**
	 * Unlinks non-null node x.
	 */
	private void unlink(Node<E> x) {
		// assert x != null;
		final Node<E> next = x.next;
		final Node<E> prev = x.prev;

		if (prev == null) {
			first = next;
		} else {
			prev.next = next;
			x.prev = null;
		}

		if (next == null) {
			last = prev;
		} else {
			next.prev = prev;
			x.next = null;
		}

		x.item = null;
		size--;
	}

	/**
	 * Inserts element e before non-null Node succ.
	 */
	private void linkBefore(E e, Node<E> succ) {
		// assert succ != null;
		final Node<E> pred = succ.prev;
		final Node<E> newNode = new Node<>(pred, e, succ);
		succ.prev = newNode;
		if (pred == null) {
			first = newNode;
		} else {
			pred.next = newNode;
		}
		size++;
	}

	/*
	 * CLASE INTERNA QUE IMPLEMENTA UN ListIterator
	 */
	private class ListItr implements ListIterator<E> {
		private Node<E> lastReturned;
		private Node<E> next;
		private int nextIndex; // Ã�ndice de next. El primero tiene Ã­ndice 0.

		ListItr() {
			next = first;
			nextIndex = 0;
		}

		@Override
		public boolean hasNext() {
			return nextIndex < size;
		}

		@Override
		public boolean hasPrevious() {
			return nextIndex > 0;
		}

		@Override
		public E next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}

			lastReturned = next;
			next = next.next;
			nextIndex++;
			return lastReturned.item;
		}

		@Override
		public int nextIndex() {
			return nextIndex;
		}

		@Override
		public E previous() {
			if (!hasPrevious()) {
				throw new NoSuchElementException();
			}

			// lastReturned = next = next == null ? last : next.prev;
			if (next == null) {
				next = last;
			} else {
				next = next.prev;
			}
			lastReturned = next;

			nextIndex--;
			return lastReturned.item;
		}

		@Override
		public int previousIndex() {
			return nextIndex - 1;
		}

		/**
		 * Replaces the last element returned by {@link #next} or {@link #previous} with
		 * the specified element (optional operation). This call can be made only if
		 * neither {@link #remove} nor {@link #add} have been called after the last call
		 * to {@code next} or {@code previous}.
		 *
		 * @param e
		 *            the element with which to replace the last element returned by
		 *            {@code next} or {@code previous}
		 * @throws IllegalStateException
		 *             if neither {@code next} nor {@code previous} have been called, or
		 *             {@code remove} or {@code add} have been called after the last
		 *             call to {@code next} or {@code previous}
		 */
		@Override
		public void set(E e) {
			if (lastReturned == null) {
				throw new IllegalStateException();
			}
			lastReturned.item = e;
		}

		/**
		 * Inserts the specified element into the list (optional operation). The element
		 * is inserted immediately before the element that would be returned by
		 * {@link #next}, if any, and after the element that would be returned by
		 * {@link #previous}, if any. (If the list contains no elements, the new element
		 * becomes the sole element on the list.) The new element is inserted before the
		 * implicit cursor: a subsequent call to {@code next} would be unaffected, and a
		 * subsequent call to {@code previous} would return the new element. (This call
		 * increases by one the value that would be returned by a call to
		 * {@code nextIndex} or {@code previousIndex}.)
		 *
		 * @param e
		 *            the element to insert
		 */
		@Override
		public void add(E e) {
			lastReturned = null;
			if (next == null) {
				linkLast(e);
			} else {
				linkBefore(e, next);
			}
			nextIndex++;
		}

		/**
		 * Removes from the list the last element that was returned by {@link #next} or
		 * {@link #previous} (optional operation). This call can only be made once per
		 * call to {@code next} or {@code previous}. It can be made only if {@link #add}
		 * has not been called after the last call to {@code next} or {@code previous}.
		 *
		 * @throws IllegalStateException
		 *             if neither {@code next} nor {@code previous} have been called, or
		 *             {@code remove} or {@code add} have been called after the last
		 *             call to {@code next} or {@code previous}
		 */
		@Override
		public void remove() {
			if (lastReturned == null) {
				throw new IllegalStateException();
			}

			Node<E> lastNext = lastReturned.next;
			unlink(lastReturned);
			if (next == lastReturned) {
				next = lastNext;
			} else {
				nextIndex--;
			}
			lastReturned = null;
		}

	}

	public static class Node<E> {
		E item;
		Node<E> next;
		Node<E> prev;

		Node(Node<E> prev, E element, Node<E> next) {
			this.item = element;
			this.next = next;
			this.prev = prev;
		}
	}
}