#
# Initiated by Jared on March 04, 2017.
#
# Main makefile for whole project.
#
#

SUBDIRS = src/concurrent \
          src/misc \
          src/lambda

.PHONY:	subdirs	 $(SUBDIRS)
subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE)	-C	$@

.PHONY: test
test:
	$(MAKE)	-C	src/test

.PHONY: clean
clean:
	$(MAKE)	-C	$(SUBDIRS)

