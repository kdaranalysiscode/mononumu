outputTree.C and .h take an input data file, filter for selection cuts (none had been applied to the bare file except 2SE and veto hits < 6), divide the data into tank hits distributions in certain beam times, scale bkg and signal templates to test consistency with the kappa parameter.  Uses Josh's poisson chisq treatment since we're generally looking at the time window tails and so we've low stats.

This particular code version lives on joe's laptop in:

	/Users/grange/Desktop/MiniBooNE/numiAnalysis/code
