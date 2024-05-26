############
Output Files
############

.. _outputFiles:

**************************************
Traj File - Velocity File - Force File
**************************************

The trajectory file is a ASCII text-file that contains the trajectory of the system, which was simulated. In general the file is structured as a standard XYZ file. The first line contains the number of atoms in the system, the second line contains important metadata of the system and the following lines contain the coordinates of the system. In case of an MD simulation, the traj_file contains repeated snapshots of the system at different time steps, all concatenated in the from of a single XYZ file. The file can be visualized using any standard visualization software like VMD, OVITO, etc.

The unit of the coordinates in the traj_file is given in :math:`\mathrm{\mathring{A}}`.

One remarkable distinction to general xyz files is the line containing the number of atoms, which is extendend in PQs trajectory files by the cell information. The cell information is given in the form of :code:`a b c alpha beta gamma`, where :code:`a`, :code:`b`, and :code:`c` are the lengths of the cell vectors and :code:`alpha`, :code:`beta`, and :code:`gamma` are the angles between the cell vectors. The cell information is given in the same units as the coordinates of the atoms.

The following is an example of a traj_file containing two snapshots of a system with 4 atoms each. Here the cell changes between the two snapshots.

.. code-block:: none

    4 10.0 15.0 10.0 90.0 120.0 90.0

    C 0.0 0.0 0.0
    H 1.0 0.0 0.0
    C 0.0 0.0 0.0
    H 1.0 0.0 0.0
    4 10.1 15.1 9.9 90.0 120.0 90.0
    
    C 0.1 0.1 0.1
    H 1.1 0.1 0.1
    C 0.1 0.1 0.1
    H 1.1 0.1 0.1

The velocity and force files are exactly the same as the traj_file, but contain the velocities and forces of the atoms instead of the coordinates.
The unit of the velocities in the vel_file is given in :math:`\mathrm{\mathring{A}}s^{-1}` and the unit of the forces in the force_file is given in kcal/mol/:math:`\mathrm{kcalmol^{-1}\mathring{A}}^{-1}`.

***********
Charge File
***********

The charge file is again very similar to the traj_file, but contains only a single scalar index per atom, which represents the charge of the atom. The unit of the charges in the charge_file is given in :math:`e`.

The following is an example of a charge_file containing the charges of a system with 4 atoms.

.. code-block:: none

    4 10.0 15.0 10.0 90.0 120.0 90.0

    0.0
    0.1
    0.0
    0.1
    4 10.1 15.1 9.9 90.0 120.0 90.0
    1.
    0.9
    1.
    0.9

***********************
Energy File & Info File
***********************






    

   