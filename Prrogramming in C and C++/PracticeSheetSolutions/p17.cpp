Book::Book(const Book& b) {
	title = new char[sizeof(b.title)];
	pages = b.pages;
}
/* b) By not implementing your own copy constructor, the compiler
 * would do the following:
 * title = b.title;
 * therefore, there would be 2 objects, pointing to the same
 * title (string) in memory. Normally, it should be two titles
 * which is why we are allocating memory for the new title
 */