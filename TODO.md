# TODO

- [ ] Setting up the project
	+ [x] Create an application struct
	+ [ ] Create a loop runner struct
	+ [ ] Choose a game library and create an application struct for it too

- [ ] Cell stuff
	+ [ ] Create a cell struct (have only ID)
	+ [ ] Create a cell array struct (cell chunk)
	+ [ ] Test if it works by implementing simple sand physics and rendering
	+ [ ] Create a cell ID options struct
	+ [ ] Create a resource manager struct (TODO: Resource Manager)
	+ [ ] Implement resource manager for cells
	+ [ ] Create a few cell ID-s for cell resource manager
	+ [ ] Implement custom update methods for cells
	+ [ ] Implement input for placing/removing cells just for fun

	- [ ] Resource Manager
		+ [ ] Create a resource manager struct and methods for it
		+ [ ] Yup, that's it, I suppose

- [ ] Advancing cells
	+ [ ] Implement double-buffering for cell array
	+ [ ] (OPTIONAL) Implement an option for each specific cell ID to be iterated either from top to bottom or from bottom to top
	+ [ ] (OPTIONAL) Implement random cell colors

- [ ] Optimizations
	+ [ ] Implement cells' alive/dead or sleeping state
		* [ ] Also make sure to make created cells to "wake up" their neighbor cells 
	+ [ ] (IF NEEDED) Optimize rendering

- [ ] (HARD) Larger cells
	+ [ ] Implement file loading/saving for cell chunks and...
	+ [ ] Implement the cell chunking.