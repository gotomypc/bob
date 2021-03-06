.. vim: set fileencoding=utf-8 :
.. Roy Wallace
.. 26 Mar 2012
.. 
.. Copyright (C) 2011-2013 Idiap Research Institute, Martigny, Switzerland

.. _section-ticketreporting:

====================================
Bug Reporting and Feature Requesting
====================================


Reporting bugs and then resolving them quickly is not an easy task. For this
reason we ask that you follow the guidelines outlined below when logging a
bug or asked for new features. Please read this entire document before submitting 
tickets. *It will help us fix your bug faster!* Bug submissions or feature requests
that do not meet these guidelines tend to be investigated last or, more likely, closed as
invalid. For great insights on bug reporting, also read through the very good
suggestions offered by `Eric Raymond's How To Ask Questions The Smart Way`_ and
`Simon Tatham's How to Report Bugs Effectively`_.

Guidelines
----------

Useful bug reports get bugs fixed, and normally have the following three
qualities:

1. **Reproducible**: If a developer can't see a bug or conclusively prove that
   it exists, the developer will probably not be able to fix it. He or she will
   move on to the next bug. Every relevant detail you provide helps.
2. **Specific**: Give us details. If you're crashing on a certain action,
   please take the time to isolate what is triggering the crash, and include it
   in the bug report if possible. The quicker the developer can isolate the
   issue to a specific problem, the more likely it will be fixed in a timely
   manner.
3. **Not a Duplicate**: Please search before filing bug reports. Try a
   variety of words in case the one(s) you're using isn't the usual one to
   describe what you're talking about. If you're running a nigthly release look
   at the associated milestone on the  Roadmap to see if your bug is already
   there. Time spent by the team sorting through different tickets on duplicate
   issues may be time not spent fixing a bug.

The list of known bugs are listed `here <https://github.com/idiap/bob/issues>`_.
If you don't find an existing ticket about your issue, then you get to file
one! If you do find an existing ticket about your problem, then it has already
been reported. This is a good thing. If you wish, you can vote on the ticket by
clicking the "up" arrow at the top of the page.

Once you have filed a bug or a feature request, please make sure you keep an eye
on the bug and answer any follow up questions that have been asked of you. If 
possible, include additional useful information.

Examples of good and bad reports
--------------------------------

Let's say you crash while running a |project| program, and want to write up a
bug report:

* **Bad report**: "My program crashed. I think I am not sure what it was. I
  think that this is a really bad problem and you should fix it or else nobody
  will use your library.  By the way, my sister thinks your web pages really
  suck. Oh, that is also the opinion of other folks down here. Thx 4 fixing
  theze bugz."
* **Useful report**: "|project| crashes immediately each time I try to use the
  ``bob::LBP4R`` type, using version 1.0.1 on a Mac OS X 10.6.5 system.  It
  crashes upon the initialization of the class. I am attaching the crash
  reports here, together with a small program that I wrote that can reproduce
  the issue."

Composing a new ticket
----------------------

Follow the link to `submit a new bug report`_ at GitHub. A few things to note:

* Please only put one issue in each ticket. File multiple tickets if you can
  confirm multiple bugs or want multiple features implemented;
* Please make sure to file your ticket in English, as that is the only language
  that most of our developers understand;
* Please keep the comments related to fixing the bug or relevant to the feature
  request;
* Please include the following information in every bug report you file:

  - A list of steps to reproduce the problem. If you need to compile a program
    to cause the bug, please create a small version of the program that still
    causes the crash and upload it with the bug report. Please keep the examples
    to an absolute minimum but also ensure that you have uploaded all of the
    files needed to reproduce the bug. When uploading these files focus on
    finding an easy way to explain your problem and make it reproducible;
  - The specific versions of |project| and the operating system that you are
    using (*not* "I'm using the latest/previous version"). You can obtain
    version numbers by executing the following script that is provided with
    |project|:

    .. code-block:: sh
       
       $ bob_config.py

.. Place here all external references for this document only

.. _Eric Raymond's How To Ask Questions The Smart Way: http://www.catb.org/~esr/faqs/smart-questions.html
.. _Simon Tatham's How to Report Bugs Effectively: http://www.chiark.greenend.org.uk/~sgtatham/bugs.html

.. All other references (that can be shared) should go to the central file:

.. include:: links.rst
