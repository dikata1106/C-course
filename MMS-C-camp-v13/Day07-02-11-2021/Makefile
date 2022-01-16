files = one two three
all: $(files)

one:
	touch $(files[0])

two:
	touch $(files[1])

three:
	touch $(files[2])

clean:
	rm -f $(files)