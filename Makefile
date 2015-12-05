DIRS = lib/inter lib/calc lib/disp src
.PHONY: all clean print
CHECK = $(shell dpkg -l | grep gnuplot)

ifdef $(CHECK)

all:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done

else

print:
	@echo "Plese install gnuplot"
	@echo "See watch Our readme.md"
	@echo "Or http://gnuplot.info"
	@echo "then try agin"
endif
