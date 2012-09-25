
SUFFIXES = .pod .man .html

CLEAN = sed -e 's,^ ,,' -e 's,^<link .* />,,'

MANARGS = -c 'User Manuals' -r 'Unix'
HTMARGS = --noindex

man1_MANS = squizz.man
man5_MANS = seqfmt.man alifmt.man

html_DATA = seqfmt.html alifmt.html

PODS = squizz.pod seqfmt.pod alifmt.pod

EXTRA_DIST = $(man1_MANS) $(man5_MANS) $(html_DATA) $(PODS)

.pod.man:
	$(POD2MAN) $(MANARGS) $< >$@ && touch $@

.pod.html:
	$(POD2HTM) $(HTMARGS) --title=$* --infile=$< | \
	  $(CLEAN) >$@ && touch $@
	@rm -f pod2htmd.tmp pod2htmi.tmp

## Maintainer parano checks
parano:
	for p in $(PODS); do \
	  podchecker --warning --warning $$p; \
	done
	for h in $(html_DATA); do \
	  xmllint --valid $$h >/dev/null; \
	done

