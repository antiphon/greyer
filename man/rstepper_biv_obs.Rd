% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/obs-rstepper-biv.R
\name{rstepper_biv_obs}
\alias{rstepper_biv_obs}
\title{Simulate the bivariate Step-Geyer model}
\usage{
rstepper_biv_obs(theta, R, K, r, bbox = cbind(0:1, 0:1), iter = 10,
  x0 = NULL, toroidal = 0, dbg = 0)
}
\arguments{
\item{theta}{weights, length K+2, first element controls intensity}

\item{R}{maximum intereaction}

\item{K}{number of steps}

\item{r}{alternative to R,K. Should be increasing, not containing 0.}

\item{bbox}{bounding box}

\item{iter}{iteration of bd}

\item{x0}{the starting pattern location matrix}

\item{toroidal}{toroidal distances?}

\item{dbg}{dbg}
}
\description{
Symmetric interaction weights
}
\details{
the steps will be (1:K)*R/K. 0 will be the beginning of the first interval, so theta[2] is mapped to range (0,r[1]).
}
