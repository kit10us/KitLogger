/*
 * Kitlogger Interface
 * https://github.com/kit10us/unify
 * Copyright (c) 2020, Kit10 Studios LLC
 *
 * This file is part of Kitlogger Interface (a.k.a. KitLogger)
 * file is part of Unify Library (a.k.a. Unify)
 *
 * Unify is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Unify is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unify.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common/CustomBlock.h>
#include <common/CustomLogger.h>
#include <common/CustomLogListener.h>
#include <iostream>
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    try
    {
        using namespace kit::debug;
        using namespace common;

        // Create the logger first, before any other logger constructs.
        CustomLogger logger;

        // Create the log listener; construct will automatically attach listener, in this case.

        logger.AttachListener( ILogListener::ptr{ std::make_shared<CustomLogListener>() } );

        // Manually create a block.
        {
            auto outer{ logger.CreateBlock( "Outer block." ) };
            outer->Log( "Log from the outer block." );

            // Manually create a second block.
            {
                auto inner{ logger.CreateBlock( "Inner block." ) };
                inner->Log( "Log from the inner block." );
            }
        }

        // Create and execute a block in one line.
        logger.CreateBlock( "Lambda block" )->Exec( []( IBlock* block )
            {
                block->Log( "Log from the logger function block" );
            }
        );
        cout << "Test Complete." << endl;

        // Hierarchical blocks.
        {
            logger.Log( "before first block" );
            logger.CreateBlock( "first block" )->Exec( []( IBlock* block )
                {
                    block->Log( "inside first block, before second block" );
                    block->SubBlock( "second block" )->Exec( []( IBlock* block )
                        {
                            block->Log( "inside second block" );
                        }
                    );
                    block->Log( "inside first block, after second block" );
                }
            );
            logger.Log( "after first block" );
        }
    }
    catch ( std::exception ex )
    {
        cout << "Exception: " << ex.what() << endl;
    }
}
