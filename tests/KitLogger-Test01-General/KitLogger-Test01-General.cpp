// Copyright (c) 2003 - 2011, Kit10 Studios LLC
// All Rights Reserved

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

        logger.AttachListener( ILogListener::ptr{ new CustomLogListener() } );

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
