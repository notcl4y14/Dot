# TODO

- [x] Setting up the project
	+ [x] Create an application struct
	+ [x] Create a loop runner struct
	+ [x] Choose a game library and create an application struct for it too

- [x] Cell stuff
	+ [x] Create a cell struct (have only ID)
	+ [x] Create a cell array struct (cell chunk)
	+ [x] Test if it works by implementing simple sand physics and rendering
	+ [x] Create a cell ID options struct
	+ [x] Create a resource manager struct (TODO: Resource Manager)
	+ [x] Implement resource manager for cells
	+ [x] Create a few cell ID-s for cell resource manager
	+ [x] Implement custom update methods for cells
	+ [x] Implement input for placing/removing cells just for fun

	- [x] Resource Manager
		+ [x] Create a resource manager struct and methods for it
		+ [x] Yup, that's it, I suppose

- [x] Advancing cells
	+ [x] Implement double-buffering for cell array
	+ [ ] (OPTIONAL) Implement an option for each specific cell ID to be iterated either from top to bottom or from bottom to top
	+ [ ] (OPTIONAL) Implement random cell colors

- [ ] Optimizations
	+ [ ] Implement cells' alive/dead or sleeping state
		* [ ] Also make sure to make created cells to "wake up" their neighbor cells 
	+ [x] (IF NEEDED) Optimize rendering

- [ ] (HARD) Larger cells
	+ [ ] Implement file loading/saving for cell chunks and...
	+ [ ] Implement the cell chunking.