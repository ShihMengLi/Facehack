//
//  KSNESolverFactory.h
//
//  正規方程式ソルバクラスのファクトリクラス
//
//  Copyright (c) 2016年 Takahiro Kosaka. All rights reserved.
//  Created by Takahiro Kosaka on 2016/04/14.
//
//

#ifndef KSNESolverFactory_h
#define KSNESolverFactory_h

#include "KSTypeDef.h"
#include "KSNormalEquationSolver.h"
#include "KSCholeskyDecomposition.h"
#include "memory.h"

namespace Kosakasakas {
    
    /**
     @brief 正規方程式ソルバクラスのファクトリクラス
     正規方程式のソルバクラスを生成するファクトリクラスです.
     */
    class KSNESolverFactory
    {
    public:
        //! コンストラクタ
        KSNESolverFactory()
        {};
        
        //! デストラクタ
        virtual ~KSNESolverFactory()
        {};
        
        //! 初期化
        bool    Initialize()
        {
            return true;
        };
        
        //! 終了処理
        void    Finalize()
        {};
        
        /**
         @brief 生成処理
         
         実際にインスタンスの生成を行う関数です.
         生成されるインスタンスはシェアードポインタ型で生成されます.
         @param type    生成するソルバのタイプ
         @return 生成されたソルバインスタンス
         */
        inline std::shared_ptr<KSNormalEquationSolver> Create(NESolverType type)
        {
            std::shared_ptr<KSNormalEquationSolver> pSolver;
            switch (type) {
                case NESolverType::CHOLESKY:
                    pSolver = std::make_shared<KSCholeskyDecomposition>();
                    break;
                    
                default:
                    pSolver = nullptr;
                    break;
            }
            return pSolver;
        }
    };
    
} //namespace Kosakasakas {


#endif /* KSNESolverFactory_h */